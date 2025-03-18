// Description: Windows API hooks.
#include "Windows.hpp"


using namespace std;

void* LoadLibraryW_orig = nullptr;

HMODULE __stdcall LoadLibraryW__hook(const wchar_t* path) {
	
	if (path == L"cri_ware_unity.dll"s) {
		//auto h = GetModuleHandle(L"GameAssembly.dll");
		//Logger::Debug(L"HOOK", L"GameAssembly handle=%p", h);
		//pedump(h, "umamusume.exe.local\\GameAssembly.dumped.dll");
		static bool loaded = false;
		if (!loaded) {
			/*auto h = GetModuleHandle(L"GameAssembly.dll");
			Logger::Debug(L"HOOK", L"Dumping GameAssembly handle=%p", h);
			pedump(h, "umamusume.exe.local\\GameAssembly.dumped.dll");*/
			//while (true) {}
			InitHooks_AfterIl2cppInit();
			loaded = true;

		}
	}
	else if (path == L"GameAssembly.dll"s) {
		Logger::Info(L"HOOK", L"Loading GameAssembly.dll");
		HMODULE module = reinterpret_cast<decltype(LoadLibraryW)*>(LoadLibraryW_orig)(path);
		Logger::Debug(L"HOOK", L"GameAssembly handle=%p", module);
		il2cpp_symbols::init(module);
		il2cpphook_init(GetProcAddress(module, "il2cpp_init"));
		Global::currenthWnd = GetActiveWindow();
		Utils::RemoveProtection(module);
		Utils::RemoveProtection(GetModuleHandle(L"umamusume.exe"));
	}
	return reinterpret_cast<decltype(LoadLibraryW)*>(LoadLibraryW_orig)(path);
}

void* RegQueryValueA_orig = nullptr;
LSTATUS RegQueryValueA_hook(
	HKEY   hKey,
	LPCSTR lpSubKey,
	LPSTR  lpData,
	PLONG  lpcbData
) {
	Logger::Info(L"HOOK", L"RegQueryValueA hook: subkey=%S", lpSubKey);
	LSTATUS ret = reinterpret_cast<decltype(RegQueryValueA)*>(RegQueryValueA_orig)(hKey, lpSubKey, lpData, lpcbData);
	Logger::Info(L"HOOK", L"Ret: ResultCode=%d, Data=%S", ret, lpData);
	return ret;
}

void* RegQueryValueExA_orig = nullptr;
LSTATUS RegQueryValueExA_hook(
	HKEY    hKey,
	LPCSTR  lpValueName,
	LPDWORD lpReserved,
	LPDWORD lpType,
	LPBYTE  lpData,
	LPDWORD lpcbData
) {
	Logger::Info(L"HOOK", L"RegQueryValueA hook: valuename=%S", lpValueName);
	LSTATUS ret = reinterpret_cast<decltype(RegQueryValueExA)*>(RegQueryValueExA_orig)(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData);
	Logger::Info(L"HOOK", L"Ret: ResultCode=%d, Data=%S\n", ret, lpData);
	return ret;
}




void WinHook_init() {
	Logger::Info(L"HOOK", L"Windows API hook initializing");
	/*MH_CreateHook(RegQueryValueA, RegQueryValueA_hook, &RegQueryValueA_orig);
	MH_EnableHook(RegQueryValueA);
	MH_CreateHook(RegQueryValueExA, RegQueryValueExA_hook, &RegQueryValueExA_orig);
	MH_EnableHook(RegQueryValueExA);*/
	MH_CreateHook(LoadLibraryW, LoadLibraryW__hook, &LoadLibraryW_orig);
	MH_EnableHook(LoadLibraryW);
	Logger::Info(L"HOOK", L"Windows API hook initialize completed");
}