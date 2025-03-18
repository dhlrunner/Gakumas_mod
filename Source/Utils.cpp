#include "Utils.h"


namespace Utils {
	DWORD GetCurrentDisplayHz() {
		DEVMODE devmode;
		memset(&devmode, 0, sizeof(DEVMODE));
		devmode.dmSize = sizeof(DEVMODE);
		devmode.dmFields = DM_DISPLAYFREQUENCY;
		EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devmode);
		return devmode.dmDisplayFrequency;
	}

	std::vector <std::string> explode(const std::string& str,
		const char& ch) {
		std::string next;
		std::vector < std::string > result;

		// For each character in the string
		for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
			// If we've hit the terminal character
			if (*it == ch) {
				// If we have some characters accumulated
				if (!next.empty()) {
					// Add them to the result vector
					result.push_back(next);
					next.clear();
				}
			}
			else {
				// Accumulate the next character into the sequence
				next += *it;
			}
		}
		if (!next.empty())
			result.push_back(next);
		return result;
	}

	std::string ConvertWstringToUTF8(const std::wstring& src)
	{
		if (src.empty()) {
			return std::string();
		}

		int size_needed = WideCharToMultiByte(CP_UTF8, 0, &src[0], (int)src.size(), NULL, 0, NULL, NULL);
		std::string result(size_needed, 0);
		WideCharToMultiByte(CP_UTF8, 0, &src[0], (int)src.size(), &result[0], size_needed, NULL, NULL);
		return result;
	}

	void RemoveProtection(HMODULE module) 
	{
		if (module == NULL) {
			std::cerr << "GetModuleHandle failed: " << GetLastError() << std::endl;
		}
		MODULEINFO moduleInfo;
		if (!GetModuleInformation(GetCurrentProcess(), module, &moduleInfo, sizeof(moduleInfo))) {
			std::cerr << "GetModuleInformation failed: " << GetLastError() << std::endl;
		}
		SIZE_T moduleSize = moduleInfo.SizeOfImage;
		DWORD oldProtect;
		if (!VirtualProtect(module, moduleSize, PAGE_EXECUTE_READWRITE, &oldProtect)) {
			std::cerr << "VirtualProtect failed: " << GetLastError() << std::endl;
		}

		std::cout << "Memory protection removed" << std::endl;
	}
}