#pragma once
#include <Windows.h>
#include <Psapi.h>
#include <locale>
#include <filesystem>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <format>
#include <functional>

namespace Utils
{
	DWORD GetCurrentDisplayHz();
	std::vector <std::string> explode(const std::string& str, const char& ch);
	std::string ConvertWstringToUTF8(const std::wstring& src);
	void RemoveProtection(HMODULE module);
}