#pragma once
#include "../../Global.h"
#include "..\..\tools\Logger.hpp"
#include "il2cpp\il2cpp_symbols.hpp"
#include "il2cpp\il2cpp-tabledefs.h"
#include "il2cpp/il2cpp-tools.hpp"
#include "..\..\Settings.h"
#include "..\..\Utils.h"
#include "..\hook-helper.h"
#include "UnityStructs.h"

#define SECTION_NAME L"UNITY_GUI"

using namespace Unity;

namespace UnityEngine::GUI
{
	void Init();
}