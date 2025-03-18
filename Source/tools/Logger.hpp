#pragma once

#include <string>
#include <cstdarg>   // va_list, va_start, va_end
#include <cstdio>    // wprintf, vswprintf_s
#include <cwchar>    // swprintf_s
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>

#ifdef _WIN32
#include <Windows.h>
#endif

class Logger
{
public:
    static void Info(const wchar_t* section, const wchar_t* format, ...);
    static void Warn(const wchar_t* section, const wchar_t* format, ...);
	static void Debug(const wchar_t* section, const wchar_t* format, ...);
    static void Error(const wchar_t* section, const wchar_t* format, ...);

private:
    static void LogMessage(const char* colorAscii, const wchar_t* level, const wchar_t* section, const wchar_t* format, va_list args);
    static std::wstring GetCurrentDateTime();
};
