#include "hook-helper.h"

bool EnableHook(LPVOID pTarget, LPVOID pDetour, LPVOID* ppOriginal, const wchar_t* hookName) {
	// Create a hook for the target function if pTarget is not nullptr
	if (pTarget != nullptr) {
		auto cRet = MH_CreateHook(pTarget, pDetour, ppOriginal);
		if (cRet != MH_OK) {
			Logger::Error(SECTION_NAME, L"MH_CreateHook Failed for target \"%s\", Status %d", hookName, cRet);
			return false;
		}
		else {
			if (MH_EnableHook(pTarget) != MH_OK) {
				Logger::Error(SECTION_NAME, L"MH_EnableHook Failed for target \"%s\"", hookName);
				return false;
			}
			else {
				Logger::Debug(SECTION_NAME, L"Hooked target \"%s\", ptr=%p", hookName, pTarget);
				return true;
			}
		}

	}
	else {
		Logger::Error(SECTION_NAME, L"Failed to create hook for target \"%s\". Target is nullptr", hookName);
		return false;
	}
	
}