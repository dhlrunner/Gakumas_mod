#include "Logger.hpp"


void Logger::Info(const wchar_t* section, const wchar_t* format, ...)
{
    va_list args;
    va_start(args, format);
	//white color
    LogMessage("\033[0m", L"INFO", section, format, args);
    va_end(args);
}

void Logger::Warn(const wchar_t* section, const wchar_t* format, ...)
{
    va_list args;
    va_start(args, format);
	//yellow color
    LogMessage("\033[33m", L"WARN", section, format, args);
    va_end(args);
}

void Logger::Debug(const wchar_t* section, const wchar_t* format, ...)
{
    va_list args;
    va_start(args, format);
	LogMessage("\033[36m", L"DEBUG", section, format, args);
    va_end(args);
}

void Logger::Error(const wchar_t* section, const wchar_t* format, ...)
{
    va_list args;
    va_start(args, format);
	//red color
    LogMessage("\033[31m", L"ERROR", section, format, args);
    va_end(args);
}


void Logger::LogMessage(const char* colorAscii, const wchar_t* level, const wchar_t* section, const wchar_t* format, va_list args)
{
    wchar_t messageBuffer[1024];
    vswprintf_s(messageBuffer, format, args);

    //yyyy-MM-dd HH:mm:ss.fff
    std::wstring dateTime = GetCurrentDateTime();

    //최종출력
    wchar_t finalBuffer[2048];
    swprintf_s(finalBuffer, L"[%s] [%s] [%s] %s\n",
        dateTime.c_str(),
        level,
        section,
        messageBuffer);
    //wprintf(L"%s\033[0m", finalBuffer);
    printf("%s%ls\033[0m", colorAscii, finalBuffer);
}

std::wstring Logger::GetCurrentDateTime()
{
    using namespace std::chrono;

    // 현재 시각을 time_t로 변환
    system_clock::time_point now = system_clock::now();
    std::time_t nowTimeT = system_clock::to_time_t(now);

    // 밀리초 계산
    auto ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;

    // tm 구조체에 로컬 시간으로 변환
    struct tm timeInfo;
#ifdef _WIN32
    localtime_s(&timeInfo, &nowTimeT);
#else
    localtime_r(&nowTimeT, &timeInfo);
#endif

    // 포매팅(HH:mm:ss.fff)
    std::wstringstream wss;
    //%Y-%m-%d
    wss << std::put_time(&timeInfo, L"%H:%M:%S")
        << L"." << std::setw(3) << std::setfill(L'0') << ms.count();

    return wss.str();
}
