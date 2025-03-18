#pragma once
#include "..\..\tools\Logger.hpp"
#include "il2cpp\il2cpp_symbols.hpp"
#include "il2cpp\il2cpp-tabledefs.h"
#include "..\..\Settings.h"
#include "..\..\Utils.h"
#include "..\hook-helper.h"
#include "UnityStructs.h"

#define SECTION_NAME L"UNITY_INPUT"

using namespace Unity;

namespace UnityEngine::InputLegacyModule
{
	extern bool (*GetKeyDown)(KeyCode);
	extern bool (*GetKey)(KeyCode);

	void Init();
}