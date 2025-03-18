#pragma once
#pragma warning(disable: 4996)

#include <vector>
#include <fstream>
#include <string>

#include "../../deps/rapidjson/document.h"
#include "../../deps/rapidjson/istreamwrapper.h"
#include "../../deps/rapidjson/encodings.h"
#include "../../deps/rapidjson/prettywriter.h"
#include "../../deps/rapidjson/filewritestream.h"
#include "../../deps/rapidjson/stringbuffer.h"
#include "../../tools/Logger.hpp"
#include "../../hooks/Unity/il2cpp/il2cpp_symbols.hpp"


namespace Settings {
    //must be value name = json config member name
    struct GlobalUmaSettings {
        bool dumpStaticEntries = false;
        bool enableLogger = false;
        bool enableConsole = false;
        bool autoFpsSet = false;
        int maxFps = -1;
        bool unlockSize = false;
        float uiScale = 1.0f;
        bool replaceFont = true;
        bool autoFullscreen = true;
        bool lz4Encrypt = true;
        bool showLiveTitleWindow = true;
        bool sendHorseMeterData = false;
        bool saveMsgPack = false;
        bool dumpGameassembly = false;
        float rankUIShowMeter = 0.0f;
        float rankUIHideoffset = 0.0f;
        bool liveCharaAutoDressReplace = false;
        bool useExclusiveFullScreen = false;
        int exclusiveFullScreenWidth = 1920;
        int exclusiveFullScreenHeight = 1080;
        char* customHost = (char*)"";
        char* customDataPath = (char*)"";
        bool skipResourceDownload = false;
        bool forceLandscape = false;
        bool highQuality = true;
        bool passPacket = false;
        char* serverIP = (char*)"127.0.0.1";
        int serverPort = 80;
        bool isTapEffectEnabled = true;
        bool isShowLiveFPSGraph = true;
        bool isShowLivePerfInfo = true;
        float virtualResolutionMultiple = 1.0f;
        bool enableVSync = false;
        bool gotoTitleOnError = true; //N
        bool walkMotionAllUrara = false;
        bool homeAllDiamond = false;
        bool winMotion564 = false;

    };

    struct LocalUmaSettings {
        int gachaCutinChara = -1;
        int gachaCutinDress = -1;
        int gachaCutinHeadid = -1;
        int raceResultCutinMotionChara = -1;
        int raceResultCutinMotionDress = -1;
        int raceResultCutinMotionGrade = -1;
        int raceResultCutinMotionRank = -1;
        bool stopLiveCam = false;
        bool changeStoryChar = false;
        int story3dCharID = -1;
        int story3dClothID = -1;
        int story3dMobid = -1;
        int story3dHeadID = -1;
        int antialiasing = 8;
        int graphics_quality = 2;
        int vsync_count = 0;
        int cardid = -1;
        float aspect_ratio = 16.f / 9.f;
        int gachaCharaType = -1;
        bool isLiveTimeManual = false;
        bool isShowLivePerfInfo = true;
        bool isShowLiveFPSGraph = false;
        bool isCanInputCommands = true;
    };

    extern GlobalUmaSettings* Global;
    extern const GlobalUmaSettings* InitialValue;
    extern LocalUmaSettings* Local;

	void Init();
	bool LoadSettings(const char* fileName);
	bool SaveSettings(const char* fileName);
}
