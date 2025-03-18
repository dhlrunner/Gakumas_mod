#include "Unity.h"

namespace Unity {

	void HookInit() {
		Logger::Info(L"UNITYHOOK", L"Unity Hook Init");
		UnityEngine::Application::Init();
		UnityEngine::CoreModule::Init();
		UnityEngine::InputLegacyModule::Init();
		UnityEngine::AssetBundle::Init();
		UnityEngine::UI::Init();
		
	}
}