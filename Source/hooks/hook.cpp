#include "hook.h"


bool InitHooks_DLLMain()
{
	if (MH_Initialize() != MH_OK) {
		Logger::Error(L"HOOK", L"Failed to initialize MinHook");
		return false;
	}
	
	//init settings
	Settings::Init();
	Settings::LoadSettings("gakumas.exe.local\\config.json");

	//Enable windows api hooks
	WinHook_init();
	
	
	
	
	return true;
}

void InitHooks_BeforeBoot()
{

}

void InitHooks_AfterIl2cppInit()
{
	//Imgui init
	ImGuiWindows::InitKiero();

	//init global
	Global::currSceneName = il2cpp_string_new16(L"_Boot");

	//Unity Init
	Unity::HookInit();

	//Set the flag
	Global::Game_HookFinished = true;

	//thread start
	BackgroundWorker::Init();


}
