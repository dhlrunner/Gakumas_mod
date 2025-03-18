#pragma once
#define IMGUI_DEFINE_MATH_OPERATORS
#define NOMINMAX


#include <Windows.h>

#include "imgui.h"
#include "backends/imgui_impl_win32.h"
#include "backends/imgui_impl_dx11.h"
#include "imgui_internal.h"
#include "imgui_notify.h"


#include "d3d11.h"
#include <wincodec.h>

#include "../kiero/kiero.h"

#include "../../Global.h"
#include "../../deps/implot/implot.h"
#include "../../hooks/Unity/UnityEngine.CoreModule.h"
#include "../../hooks/Unity/UnityEngine.Application.h"

#pragma comment(lib, "d3d11.lib")



namespace ImGuiWindows
{
	extern void InitKiero();
}

