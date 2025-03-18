#include "UnityEngine.Application.h"

namespace UnityEngine::Application {

	Il2CppString* (*get_persistentDataPath_addr)();

	void* get_persistentDataPath_orig = nullptr;
	Il2CppString* get_persistentDataPath_hook() {
		Il2CppString* ret = reinterpret_cast<decltype(get_persistentDataPath_hook)*>
			(get_persistentDataPath_orig)();

		if (strlen(Settings::Global->customDataPath) > 0) {
			Il2CppString* custompath = il2cpp_string_new(Settings::Global->customDataPath);
			//wprintf(L"[unityengine_get_persistentDataPath] originalpersistentpath=%s, replacedpersistentpath=%s\n", ret->start_char, custompath->start_char);
			return custompath;
		}

		return ret;
	}

	void* set_targetFrameRate_orig = nullptr;
	void set_targetFrameRate_hook(int value)
	{
		if (Settings::Global->autoFpsSet) {
			Settings::Global->maxFps = Utils::GetCurrentDisplayHz();
			Logger::Info(L"UNITYHOOK", L"Auto fps limit setted : %d fps", Settings::Global->maxFps);
		}
		else {
			Logger::Info(L"UNITYHOOK", L"fps limit setted : %d fps", Settings::Global->maxFps);
		}
		value = Settings::Global->maxFps;
		return reinterpret_cast<decltype(set_targetFrameRate_hook)*>(set_targetFrameRate_orig)(value);

	}


	void Init() {
		Logger::Info(L"UNITYHOOK", L"UnityEngine.Application Hook Init");

		auto set_fps_addr = il2cpp_resolve_icall("UnityEngine.Application::set_targetFrameRate(System.Int32)");
		EnableHook(set_fps_addr, &set_targetFrameRate_hook, &set_targetFrameRate_orig, L"Unity_set_targetFrameRate");

		get_persistentDataPath_addr = reinterpret_cast<Il2CppString * (*)()>(il2cpp_resolve_icall("UnityEngine.Application::get_persistentDataPath()"));
		EnableHook(get_persistentDataPath_addr, &get_persistentDataPath_hook, &get_persistentDataPath_orig, L"Unity_get_persistentDataPath");

		
	}
}