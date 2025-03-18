#pragma once
#include <wtypes.h>
#include <vector>
#include "hooks/Unity/il2cpp/il2cpp_symbols.hpp"
#include "hooks/Unity/il2cpp/il2cppDictionary.hpp"

namespace Global 
{
	//레이스 결과 화면에서 착순 아이콘 플래시 표시 여부
	extern bool showFinishOrderFlash;

	extern int liveTimeLineFPS;
	extern float liveTimeSec;
	extern float liveTotalTimeSec;
	extern float oldLiveTime;
	extern float liveTimelineManualScale;
	extern bool showFinishOrderFlash;
	extern bool isShowingSeekbar;
	//extern int currSceneID;
	extern Il2CppString* currSceneName;
	extern bool isKimuraChallenge;

	extern bool settingUpImageEffect;

	extern bool toastImGui;
	extern char* toastMessage;
	extern bool imgui_settingwnd_open;

	extern bool gameTerminating;

	extern HWND currenthWnd;

	extern bool Game_HookFinished;

	extern bool isNeedFullscreen;


}