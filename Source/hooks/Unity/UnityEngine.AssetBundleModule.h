#pragma once
#include "..\..\tools\Logger.hpp"
#include "il2cpp\il2cpp_symbols.hpp"
#include "il2cpp\il2cpp-tabledefs.h"
#include "..\..\Settings.h"
#include "..\..\Utils.h"
#include "..\hook-helper.h"
#include "UnityStructs.h"

#define SECTION_NAME L"UNITYASSETBUNDLE"
using namespace Unity;

namespace UnityEngine::AssetBundle
{
	extern void* (*LoadInternal)(Il2CppString*, unsigned int, unsigned long);

	void Init();
}