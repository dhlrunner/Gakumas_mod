#include "Unityengine.CoreModule.h"

using namespace Unity;
using namespace std;

namespace UnityEngine::CoreModule
{
	Il2CppString* (*GetGraphicsDeviceName)();
	void* (*GameObject_Find)(Il2CppString*);
	void (*LoadScene)(Il2CppString*, LoadSceneParameters*);
	void (*set_TimeScale)(float);
	float (*get_TimeScale)();
	void (*get_resolution)(Resolution_t* buffer);

	void ResetGame() {
		LoadSceneParameters p = { 0 };
		p.LoadSceneMode = 0; //Single
		p.LocalPhysicsMode = 0;
		LoadScene(il2cpp_string_new(string("_Boot").data()), &p);
	}

	void GameObject_SetActive(const char* path, bool enable) {
		Il2CppObject* gobj = (Il2CppObject*)GameObject_Find(il2cpp_string_new(string(path).data()));
		auto gobj_setActive = reinterpret_cast<void (*)
			(Il2CppObject * _instance, bool value)>(il2cpp_class_get_method_from_name(gobj->klass, "SetActive", 1)->methodPointer);
		if (gobj != nullptr) {
			Logger::Debug(SECTION_NAME, L"Get GameObj path=%S, res=0x%p, SetActive %d", path, &gobj, enable);
			gobj_setActive(gobj, enable);
		}
		else {
			Logger::Error(SECTION_NAME, L"Error: Get GameObj path=%s is nullptr!!", path);
		}

	}

	void* Screen_set_orientation_orig = nullptr;
	void Screen_set_orientation_hook(ScreenOrientation orientation) {
		Logger::Debug(SECTION_NAME, L"SetScreenOrientation Hook %d", orientation);
		if ((orientation == ScreenOrientation::Portrait ||
			orientation == ScreenOrientation::PortraitUpsideDown) && Settings::Global->forceLandscape) {
			orientation = ScreenOrientation::Landscape;
		}
		reinterpret_cast<decltype(Screen_set_orientation_hook)*>(Screen_set_orientation_orig)(
			orientation);
	}

	void* set_vSyncCount_orig = nullptr;
	void set_vSyncCount_hook(int value) {
		Logger::Info(SECTION_NAME, L"setVsyncCount: %d -> %d", value, Settings::Local->vsync_count);
		return reinterpret_cast<decltype(set_vSyncCount_hook)*>(set_vSyncCount_orig)
			(Settings::Local->vsync_count == -1 ? value : Settings::Local->vsync_count);
	}

	void* set_antiAliasing_orig = nullptr;
	void set_antiAliasing_hook(int value) {
		Logger::Info(SECTION_NAME, L"setAntialiasing: %d -> %d", value, Settings::Local->antialiasing);
		set_vSyncCount_hook(1);
		return reinterpret_cast<decltype(set_antiAliasing_hook)*>(set_antiAliasing_orig)
			(Settings::Local->antialiasing == -1 ? value : Settings::Local->antialiasing);
	}

	void* set_RenderTextureAntiAliasing_orig;
	void set_RenderTextureAntiAliasing_hook(void* _this, int value) {
		return reinterpret_cast<decltype(set_RenderTextureAntiAliasing_hook)*>(set_RenderTextureAntiAliasing_orig)(_this,
			Settings::Local->antialiasing == -1 ? value : Settings::Local->antialiasing);
	}

	

	void* Application_Quit_orig;
	void Application_Quit_hook(int code) {
		Logger::Info(SECTION_NAME, L"Application.Quit() hooked Code->%d", code);
		//system("pause");
		//printf("App will quit after 5 seconds\n");
		//Sleep(5000);
		//return;
		Global::gameTerminating = true;
		reinterpret_cast<decltype(Application_Quit_hook)*>(Application_Quit_orig)(code);
	}

	void* LoadSceneAsyncNameIndexInternal_orig = nullptr;
	void* LoadSceneAsyncNameIndexInternal_hook(Il2CppString* sceneName, int sceneBuildIndex, LoadSceneParameters* parameters, bool mustCompleteNextFrame)
	{
		//wcscpy_s(Global::currSceneName, sceneName->length, sceneName->chars);
		Logger::Debug(SECTION_NAME, L"LoadSceneAsyncNameIndexInternal hooked name=%S", Utils::ConvertWstringToUTF8(sceneName->chars).c_str());
		Global::currSceneName = sceneName;
		wstring sceneN = sceneName->chars;
		

		return reinterpret_cast<decltype(LoadSceneAsyncNameIndexInternal_hook)*>(LoadSceneAsyncNameIndexInternal_orig)(sceneName, sceneBuildIndex, parameters, mustCompleteNextFrame);
	}

	void* SetResolution_Injected_orig;
	void SetResolution_Injected_hook(int width, int height, Unity::FullScreenMode fullscreenMode, Unity::RefreshRate* perferredRefreshRate)
	{
		Logger::Info(SECTION_NAME, L"SetResolution_Injected %d %d %d %d/%d", width, height, fullscreenMode, perferredRefreshRate->denominator, perferredRefreshRate->numerator);
		if (Settings::Global->autoFullscreen)
		{
			Resolution_t r;
			get_resolution(&r);

			bool needFullscreen = false;

			/*if (Gallop::StandaloneWindowResize::get_IsVirt != nullptr) {
				if (Gallop::StandaloneWindowResize::get_IsVirt() && r.width / static_cast<double>(r.height) == (9.0 / 16.0))
					needFullscreen = true;
				else if (!Gallop::StandaloneWindowResize::get_IsVirt() && r.width / static_cast<double>(r.height) == (16.0 / 9.0))
					needFullscreen = true;
			}*/


			if (needFullscreen)
			{
				
				if (Settings::Global->useExclusiveFullScreen)
				{
					if (Settings::Global->exclusiveFullScreenWidth > 0 && Settings::Global->exclusiveFullScreenHeight > 0) {

						return reinterpret_cast<decltype(SetResolution_Injected_hook)*>(SetResolution_Injected_orig)(
							Settings::Global->exclusiveFullScreenWidth,
							Settings::Global->exclusiveFullScreenHeight,
							FullScreenMode::ExclusiveFullScreen, perferredRefreshRate);
						Sleep(1000);
					}
					else {

						return reinterpret_cast<decltype(SetResolution_Injected_hook)*>(SetResolution_Injected_orig)(
							r.width, r.height, FullScreenMode::FullScreenWindow, perferredRefreshRate);
						Sleep(1000);
					}

				}
				else
				{

					return reinterpret_cast<decltype(SetResolution_Injected_hook)*>(SetResolution_Injected_orig)(
						r.width, r.height, FullScreenMode::FullScreenWindow, perferredRefreshRate);


				}
			}
			/*else
			{
				printf("NeedFullScreen\n");
				return reinterpret_cast<decltype(SetResolution_Injected_hook)*>(SetResolution_Injected_orig)(
					r.width, r.height, FullScreenMode::Windowed, perferredRefreshRate);
			}*/

		}
		

		printf("NeedFullScreen\n");
		return reinterpret_cast<decltype(SetResolution_Injected_hook)*>(SetResolution_Injected_orig)
			(width, height, fullscreenMode, perferredRefreshRate);
	}


#pragma region UserCode
	void get_resolution_stub(Resolution_t* r)
	{
		get_resolution(r);

		int width = min(r->height, r->width) * Settings::Local->aspect_ratio;
		if (r->width > r->height)
			r->width = width;
		else
			r->height = width;
	}

	void adjustScreenSize(int w, int h)
	{
		Logger::Info(SECTION_NAME, L"Adjusting screen size %d %d", w, h);
		thread([&]() {
			auto tr = il2cpp_thread_attach(il2cpp_domain_get());

			Resolution_t r ;
			get_resolution(&r);

			Logger::Debug(SECTION_NAME, L"get resolution %d %d", r.height, r.width);

			auto targetHeight = r.height - 100;
			if (w > 0 && h > 0) {
				//TODO: GetCurrentDisplayHz 대신 현재 프레임 입력
				SetResolution_Injected_hook(h * 0.5625f, h, FullScreenMode::Windowed, new RefreshRate{ 0,1 });
			}
			else {
				SetResolution_Injected_hook(targetHeight * 0.5625f, targetHeight, FullScreenMode::Windowed, new RefreshRate{ 0,1 });
			}


			il2cpp_thread_detach(tr);
		}).detach();
	}
#pragma endregion

	

	void Init() 
	{
		Logger::Info(SECTION_NAME, L"Init");

		auto Screen_set_orientation_addr = reinterpret_cast<void (*)(
			ScreenOrientation)>(il2cpp_symbols::get_method_pointer(
				"UnityEngine.CoreModule.dll",
				"UnityEngine",
				"Screen", "set_orientation", 1));
		EnableHook(Screen_set_orientation_addr, &Screen_set_orientation_hook, &Screen_set_orientation_orig, L"Screen_set_orientation");

		GameObject_Find = reinterpret_cast<void* (*)(Il2CppString*)>(il2cpp_symbols::get_method_pointer(  
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"GameObject", "Find", 1
		));

		GetGraphicsDeviceName = reinterpret_cast<Il2CppString * (*)()>(il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine", "SystemInfo", "GetGraphicsDeviceName", 0
		));
		
		/*GameObject_SetActive = reinterpret_cast<void(*)(void*, bool)>(
			il2cpp_symbols::get_method_pointer(
				"UnityEngine.CoreModule.dll", "UnityEngine",
				"GameObject", "SetActive", 1
			)
			);*/

		auto set_vSyncCount_addr = il2cpp_resolve_icall("UnityEngine.QualitySettings::set_vSyncCount(System.Int32)");
		EnableHook(set_vSyncCount_addr, &set_vSyncCount_hook, &set_vSyncCount_orig, L"set_vSyncCount");

		auto set_antiAliasing_addr = il2cpp_resolve_icall("UnityEngine.QualitySettings::set_antiAliasing(System.Int32)");
		EnableHook(set_antiAliasing_addr, &set_antiAliasing_hook, &set_antiAliasing_orig, L"set_antiAliasing");

		auto set_RenderTextureAntiAliasing_addr = il2cpp_symbols::get_method_pointer(
			"UnityEngine.CoreModule.dll", "UnityEngine",
			"RenderTexture", "set_antiAliasing", 1
		);
		EnableHook(set_RenderTextureAntiAliasing_addr, &set_RenderTextureAntiAliasing_hook, &set_RenderTextureAntiAliasing_orig, L"set_RenderTextureAntiAliasing");

		
		
		LoadScene = reinterpret_cast<void(*)(Il2CppString*, LoadSceneParameters*)>(
			il2cpp_symbols::get_method_pointer(
				"UnityEngine.CoreModule.dll", "UnityEngine.SceneManagement",
				"SceneManager", "LoadScene", 2
			));

		set_TimeScale = reinterpret_cast<void(*)(float)>(
			il2cpp_symbols::get_method_pointer(
				"UnityEngine.CoreModule.dll", "UnityEngine",
				"Time", "set_timeScale", 1
			));

		get_TimeScale = reinterpret_cast<float(*)()>(
			il2cpp_symbols::get_method_pointer(
				"UnityEngine.CoreModule.dll", "UnityEngine",
				"Time", "get_timeScale", 0
			));

		auto Application_Quit_addr = il2cpp_resolve_icall("UnityEngine.Application::Quit(System.Int32)");
		EnableHook(Application_Quit_addr, &Application_Quit_hook, &Application_Quit_orig, L"Application_Quit");

		auto LoadSceneAsyncNameIndexInternal_addr = il2cpp_resolve_icall("UnityEngine.SceneManagement.SceneManagerAPIInternal::LoadSceneAsyncNameIndexInternal_Injected(System.String,System.Int32,UnityEngine.SceneManagement.LoadSceneParameters&,System.bool)");
		EnableHook(LoadSceneAsyncNameIndexInternal_addr, &LoadSceneAsyncNameIndexInternal_hook, &LoadSceneAsyncNameIndexInternal_orig, L"LoadSceneAsyncNameIndexInternal");

		auto SetResolution_Injected_addr = il2cpp_resolve_icall("UnityEngine.Screen::SetResolution_Injected(System.Int32,System.Int32,UnityEngine.FullScreenMode,UnityEngine.RefreshRate)");
		EnableHook(SetResolution_Injected_addr, &SetResolution_Injected_hook, &SetResolution_Injected_orig, L"SetResolution_Injected");
		

		get_resolution = reinterpret_cast<decltype(get_resolution)>(il2cpp_resolve_icall("UnityEngine.Screen::get_currentResolution_Injected(UnityEngine.Resolution&)"));
		//if (Settings::Global->autoFullscreen)
		//	adjustScreenSize();
		//adjustScreenSize();
	
	}
}