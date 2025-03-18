#include "Campus.h"

namespace Campus
{
	void Init()
	{
		Logger::Info(SECTION_NAME, L"Campus Hook Init");

		Campus::OutGame::InquiryEncryptUtility::Init();

		//QoaLogger
		Qua::LoggerManagement::Logger_::QuaLogger::Init();
	}
}