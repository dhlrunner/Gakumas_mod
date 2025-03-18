#include "QuaLogger.h"

namespace Qua::LoggerManagement::Logger_::QuaLogger
{
	void* Log_orig = nullptr;
	void Log_hook(Il2CppObject* _this, int logLevel, int eventId, Il2CppString* message, void* exception)
	{
		printf("\033[94m[%s] %s\033[0m\n", logLevel == 0 ? "DEBUG" : logLevel == 1 ? "INFO" : logLevel == 2 ? "WARN" : logLevel == 3 ? "ERROR" : "UNKNOWN", Utils::ConvertWstringToUTF8(message->chars).c_str());
		reinterpret_cast<decltype(Log_hook)*>(Log_orig)(_this, logLevel, eventId, message, exception);
	}

	void Init() {
		Logger::Info(SECTION_NAME, L"Init");

		auto Log_addr = reinterpret_cast<void(*)(Il2CppObject*, int, int, Il2CppString*, void*)>(
			il2cpp_symbols::get_method_pointer(
				"quaunity-logger.dll", "Qua.LoggerManagement.Logger",
				"QuaLogger", "Log", 4
			));
		EnableHook(Log_addr, &Log_hook, &Log_orig, L"QuaLogger.Log");
	}
}