#include "Global.h"

namespace Global
{
	//글로벌 변수값 초기화
	bool showFinishOrderFlash = true;
	int liveTimeLineFPS = 0;
	float liveTimeSec = 0.0f;
	float liveTotalTimeSec = 0.0f;
	float liveTimelineManualScale = 0.1;
	float oldLiveTime = 0.0f;
	bool settingUpImageEffect = false;
	bool toastImGui = false;
	char* toastMessage = nullptr;

	bool imgui_settingwnd_open = false;

	bool gameTerminating = false;

	bool isShowingSeekbar = false;
	//int currSceneID = -1;
	Il2CppString* currSceneName;
	bool isKimuraChallenge = false;
	HWND currenthWnd = NULL;
	bool Game_HookFinished = false;


	bool isNeedFullscreen = false;
}