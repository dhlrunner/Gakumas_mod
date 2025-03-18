#include "UnityEngine.AssetBundleModule.h"

namespace UnityEngine::AssetBundle
{
	void* (*LoadInternal)(Il2CppString*, unsigned int, unsigned long) = nullptr;

	void Init()
	{
		Logger::Info(SECTION_NAME, L"Init");
		LoadInternal = reinterpret_cast<void* (*)(Il2CppString*, unsigned int, unsigned long)>(
			il2cpp_resolve_icall("UnityEngine.AssetBundle::LoadFromFile_Internal(System.String,System.UInt32,System.UInt64)")
		);
	}
}