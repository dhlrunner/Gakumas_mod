#pragma once
#include "..\..\tools\Logger.hpp"
#include "il2cpp\il2cpp_symbols.hpp"
#include "il2cpp\il2cpp-tabledefs.h"
#include "..\..\Settings.h"
#include "..\..\Utils.h"
#include "..\hook-helper.h"
#include "UnityStructs.h"

#define SECTION_NAME L"UNITY_UI"

using namespace Unity;

namespace UnityEngine::UI
{
	extern void (*set_scaleFactor)(void*, float);
	void Init();
}