#pragma once
#include "../../tools/Logger.hpp"
#include "UnityEngine.Application.h"
#include "UnityEngine.CoreModule.h"
#include "UnityEngine.InputLegacyModule.h"
#include "UnityEngine.AssetBundleModule.h"
#include "UnityEngine.UI.h"

namespace Unity {
	void HookInit();
}