#pragma once
#include "..\..\tools\Logger.hpp"
#include "il2cpp\il2cpp_symbols.hpp"
#include "il2cpp\il2cpp-tabledefs.h"
#include "..\..\Settings.h"
#include "..\..\Utils.h"
#include "..\hook-helper.h"


namespace UnityEngine::Application
{
	Il2CppString* get_persistentDataPath_hook();
	void set_targetFrameRate_hook(int value);
	void Init();
}