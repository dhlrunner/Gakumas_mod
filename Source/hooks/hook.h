#define STB_IMAGE_IMPLEMENTATION

#pragma once
#include "../hooks/Unity/Unity.h"
#include "../hooks/Windows/Windows.hpp"
#include "../hooks/Campus/Campus.h"

#include "../../tools/Logger.hpp"
#include "../../tools/imgui/ImguiWindows.h"
#include "../../Settings.h"
#include "../Global.h"
#include "../../deps/minhook/include/MinHook.h"

#include "Unity/il2cpp/il2cpp_dump.h"

#include "BackgroundWorker.h"

bool InitHooks_DLLMain();
void InitHooks_BeforeBoot();
void InitHooks_AfterIl2cppInit();