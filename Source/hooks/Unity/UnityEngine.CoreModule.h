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

#include <thread>
#include <numeric>

#define SECTION_NAME L"UNITY_CORE"

using namespace Unity;

namespace UnityEngine::CoreModule
{
	extern Il2CppString* (*GetGraphicsDeviceName)();
	extern void* (*GameObject_Find)(Il2CppString*);
	extern void (*set_TimeScale)(float);
	extern float (*get_TimeScale)();
	void ResetGame();
	void GameObject_SetActive(const char* path, bool value);
	void Screen_set_orientation_hook(ScreenOrientation orientation);
	void Init();
	void adjustScreenSize(int w = 0, int h = 0);
	void get_resolution_stub(Unity::Resolution_t* r);
	void set_antiAliasing_hook(int value);
}