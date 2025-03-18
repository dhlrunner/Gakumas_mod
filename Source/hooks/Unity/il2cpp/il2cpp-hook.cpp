#include "il2cpp-hook.h"

void* il2cpp_init_orig = nullptr;
bool __stdcall il2cpp_init_hook(const char* domain_name) {
	Logger::Info(L"IL2CPP", L"il2cpp_init called");

	const auto result = reinterpret_cast<decltype(il2cpp_init_hook)*>(il2cpp_init_orig)(domain_name);
	InitHooks_BeforeBoot();
	//il2cpp_symbols::init(GetModuleHandle(L"GameAssembly.dll"));
	return true;
}

void il2cpphook_init(const FARPROC init_addr) {
	Logger::Debug(L"IL2CPP", L"Hooking il2cpp_init");
	EnableHook(init_addr, il2cpp_init_hook, &il2cpp_init_orig, L"il2cpp_init");
}
