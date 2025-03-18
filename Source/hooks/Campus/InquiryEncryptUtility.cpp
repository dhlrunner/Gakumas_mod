#include "InquiryEncryptUtility.h"

namespace Campus::OutGame::InquiryEncryptUtility
{
	void* Encrypt_orig = nullptr;
	void* Encrypt_hook(Il2CppString* appUserId, Il2CppString* commonKey, Il2CppString* saltStr) {

		Logger::Info(SECTION_NAME, L"Encrypt_hook, appUserId=%S, commonKey=%S, saltStr=%S",
			Utils::ConvertWstringToUTF8(appUserId->chars).c_str(),
			Utils::ConvertWstringToUTF8(commonKey->chars).c_str(),
			Utils::ConvertWstringToUTF8(saltStr->chars).c_str());

		return reinterpret_cast<decltype(Encrypt_hook)*>(Encrypt_orig)(appUserId, commonKey, saltStr);

	}

	void Init()
	{
		Logger::Info(SECTION_NAME, L"Init");
		
		auto Encrypt_addr = reinterpret_cast<void*(*)(Il2CppString*, Il2CppString*, Il2CppString*)>(
			il2cpp_symbols::get_method_pointer(
				"Assembly-CSharp.dll", "Campus.OutGame",
				"InquiryEncryptUtility", "Encrypt", 3
			));
		EnableHook(Encrypt_addr, &Encrypt_hook, &Encrypt_orig, L"InquiryEncryptUtility.Encrypt");
	}
}