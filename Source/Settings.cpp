#include "Settings.h"

namespace Settings {
	/// settings.json 에서 가져온 값
	GlobalUmaSettings* Global;

	/// 설정 초기값
	const GlobalUmaSettings* InitialValue;

	/// 런타임중 필요한 설정값
	LocalUmaSettings* Local;

	std::vector<std::string> dicts;

	void Init() {
		Global = new GlobalUmaSettings();
		InitialValue = new GlobalUmaSettings();
		Local = new LocalUmaSettings();

		
	}

	bool LoadSettings(const char* fileName) {
		std::ifstream config_stream{ fileName };
		std::vector<std::string> dicts{};

		if (!config_stream.is_open()) {
			Logger::Error(L"SETTINGS", L"Failed to open %S", fileName);
			return false;
		}

		rapidjson::IStreamWrapper wrapper{ config_stream };
		rapidjson::Document document;
		document.ParseStream(wrapper);

		if (document.HasParseError()) {
			Logger::Error(L"SETTINGS", L"Failed to parse %S", fileName);
			return false;
		}
		else {
			Logger::Info(L"SETTINGS", L"Loaded Setting file %S", fileName);
			Global->enableConsole = document.HasMember("enableConsole") ? document["enableConsole"].GetBool() : InitialValue->enableConsole;
			Global->enableLogger = document.HasMember("enableLogger") ? document["enableLogger"].GetBool() : InitialValue->enableLogger;
			Global->dumpStaticEntries = document.HasMember("dumpStaticEntries") ? document["dumpStaticEntries"].GetBool() : InitialValue->dumpStaticEntries;
			Global->maxFps = document.HasMember("maxFps") ? document["maxFps"].GetInt() : InitialValue->maxFps;
			Global->unlockSize = document.HasMember("unlockSize") ? document["unlockSize"].GetBool() : InitialValue->unlockSize;
			Global->uiScale = document.HasMember("uiScale") ? document["uiScale"].GetFloat() : InitialValue->uiScale;
			Global->replaceFont = document.HasMember("replaceFont") ? document["replaceFont"].GetBool() : InitialValue->replaceFont;
			Global->autoFullscreen = document.HasMember("autoFullscreen") ? document["autoFullscreen"].GetBool() : InitialValue->autoFullscreen;
			Global->autoFpsSet = document.HasMember("autoFpsSet") ? document["autoFpsSet"].GetBool() : InitialValue->autoFpsSet;
			Global->lz4Encrypt = document.HasMember("lz4Encrypt") ? document["lz4Encrypt"].GetBool() : InitialValue->lz4Encrypt;
			Global->dumpGameassembly = document.HasMember("dumpGameassembly") ? document["dumpGameassembly"].GetBool() : InitialValue->dumpGameassembly;
			Global->saveMsgPack = document.HasMember("saveMsgPack") ? document["saveMsgPack"].GetBool() : InitialValue->saveMsgPack;
			Global->showLiveTitleWindow = document.HasMember("showLiveTitleWindow") ? document["showLiveTitleWindow"].GetBool() : InitialValue->showLiveTitleWindow;
			Global->sendHorseMeterData = document.HasMember("sendHorseMeterData") ? document["sendHorseMeterData"].GetBool() : InitialValue->sendHorseMeterData;
			Global->rankUIShowMeter = document.HasMember("rankUIShowMeter") ? document["rankUIShowMeter"].GetFloat() : InitialValue->rankUIShowMeter;
			Global->rankUIHideoffset = document.HasMember("rankUIHideoffset") ? document["rankUIHideoffset"].GetFloat() : InitialValue->rankUIHideoffset;
			Global->liveCharaAutoDressReplace = document.HasMember("liveCharaAutoDressReplace") ? document["liveCharaAutoDressReplace"].GetBool() : InitialValue->liveCharaAutoDressReplace;
			Global->useExclusiveFullScreen = document.HasMember("useExclusiveFullScreen") ? document["useExclusiveFullScreen"].GetBool() : InitialValue->useExclusiveFullScreen;
			Global->exclusiveFullScreenWidth = document.HasMember("exclusiveFullScreenWidth") ? document["exclusiveFullScreenWidth"].GetInt() : InitialValue->exclusiveFullScreenWidth;
			Global->exclusiveFullScreenHeight = document.HasMember("exclusiveFullScreenHeight") ? document["exclusiveFullScreenHeight"].GetInt() : InitialValue->exclusiveFullScreenHeight;
			Global->gotoTitleOnError = document.HasMember("gotoTitleOnError") ? document["gotoTitleOnError"].GetBool() : InitialValue->gotoTitleOnError;

			Global->passPacket = document.HasMember("passPacket") ? document["passPacket"].GetBool() : InitialValue->passPacket;

			const char* s = document.HasMember("serverIP") ? document["serverIP"].GetString() : InitialValue->serverIP;
			Global->serverIP = new char[strlen(s) + 1];
			strcpy(Global->serverIP, s);

			Global->serverPort = document.HasMember("serverPort") ? document["serverPort"].GetInt() : InitialValue->serverPort;

			const char* d = document.HasMember("customHost") ? document["customHost"].GetString() : InitialValue->customHost;
			Global->customHost = new char[strlen(d) + 1];
			strcpy(Global->customHost, d);
			const char* tt = document.HasMember("customDataPath") ? document["customDataPath"].GetString() : InitialValue->customDataPath;
			Global->customDataPath = new char[strlen(tt) + 1];
			strcpy(Global->customDataPath, tt);

			Global->skipResourceDownload = document.HasMember("skipResourceDownload") ? document["skipResourceDownload"].GetBool() : InitialValue->skipResourceDownload;
			Global->forceLandscape = document.HasMember("forceLandscape") ? document["forceLandscape"].GetBool() : InitialValue->forceLandscape;
			Global->highQuality = document.HasMember("highQuality") ? document["highQuality"].GetBool() : InitialValue->highQuality;
			if (Global->highQuality) {
				Local->graphics_quality = 3;
				Local->antialiasing = 8;
				int screenWidth = GetSystemMetrics(SM_CXSCREEN);
				int screenHeight = GetSystemMetrics(SM_CYSCREEN);
			}
			else {
				Local->graphics_quality = -1;
				Local->antialiasing = -1;
			}

			Global->enableVSync = document.HasMember("enableVSync") ? document["enableVSync"].GetBool() : InitialValue->enableVSync;
			if (Global->enableVSync) {
				Local->vsync_count = 1;
			}
			else {
				Local->vsync_count = 0;
			}
			Global->walkMotionAllUrara = document.HasMember("walkMotionAllUrara") ? document["walkMotionAllUrara"].GetBool() : InitialValue->walkMotionAllUrara;
			Global->isTapEffectEnabled = document.HasMember("isTapEffectEnabled") ? document["isTapEffectEnabled"].GetBool() : InitialValue->isTapEffectEnabled;


			Global->virtualResolutionMultiple = document.HasMember("virtualResolutionMultiple") ? document["virtualResolutionMultiple"].GetFloat() : InitialValue->virtualResolutionMultiple;
			// Looks like not working for now
			// g_aspect_ratio = document["customAspectRatio"].GetFloat();

			auto& dicts_arr = document["dicts"];
			auto len = dicts_arr.Size();

			for (size_t i = 0; i < len; ++i)
			{
				auto dict = dicts_arr[i].GetString();

				dicts.push_back(dict);
			}
		}
			
	}

	bool SaveSettings(const char* fileName) {


		rapidjson::Document document;
		document.SetObject();

		rapidjson::Document::AllocatorType& allocator = document.GetAllocator();

		// Add each member of the structure to the document
		document.AddMember("dumpStaticEntries", Global->dumpStaticEntries, allocator);
		document.AddMember("enableLogger", Global->enableLogger, allocator);
		document.AddMember("enableConsole", Global->enableConsole, allocator);
		document.AddMember("autoFpsSet", Global->autoFpsSet, allocator);
		document.AddMember("maxFps", Global->maxFps, allocator);
		document.AddMember("unlockSize", Global->unlockSize, allocator);
		document.AddMember("uiScale", Global->uiScale, allocator);
		document.AddMember("replaceFont", Global->replaceFont, allocator);
		document.AddMember("autoFullscreen", Global->autoFullscreen, allocator);
		document.AddMember("lz4Encrypt", Global->lz4Encrypt, allocator);
		document.AddMember("showLiveTitleWindow", Global->showLiveTitleWindow, allocator);
		document.AddMember("sendHorseMeterData", Global->sendHorseMeterData, allocator);
		document.AddMember("saveMsgPack", Global->saveMsgPack, allocator);
		document.AddMember("dumpGameassembly", Global->dumpGameassembly, allocator);
		document.AddMember("rankUIShowMeter", Global->rankUIShowMeter, allocator);
		document.AddMember("rankUIHideoffset", Global->rankUIHideoffset, allocator);
		document.AddMember("liveCharaAutoDressReplace", Global->liveCharaAutoDressReplace, allocator);
		document.AddMember("useExclusiveFullScreen", Global->useExclusiveFullScreen, allocator);
		document.AddMember("exclusiveFullScreenWidth", Global->exclusiveFullScreenWidth, allocator);
		document.AddMember("exclusiveFullScreenHeight", Global->exclusiveFullScreenHeight, allocator);
		document.AddMember("customHost", rapidjson::StringRef(Global->customHost), allocator);
		document.AddMember("customDataPath", rapidjson::StringRef(Global->customDataPath), allocator);
		document.AddMember("skipResourceDownload", Global->skipResourceDownload, allocator);
		document.AddMember("forceLandscape", Global->forceLandscape, allocator);
		document.AddMember("highQuality", Global->highQuality, allocator);
		document.AddMember("passPacket", Global->passPacket, allocator);
		document.AddMember("serverIP", rapidjson::StringRef(Global->serverIP), allocator);
		document.AddMember("serverPort", Global->serverPort, allocator);
		document.AddMember("isTapEffectEnabled", Global->isTapEffectEnabled, allocator);
		document.AddMember("isShowLiveFPSGraph", Global->isShowLiveFPSGraph, allocator);
		document.AddMember("isShowLivePerfInfo", Global->isShowLivePerfInfo, allocator);
		document.AddMember("gotoTitleOnError", Global->gotoTitleOnError, allocator);
		document.AddMember("virtualResolutionMultiple", Global->virtualResolutionMultiple, allocator);
		document.AddMember("enableVSync", Global->enableVSync, allocator);
		document.AddMember("walkMotionAllUrara", Global->walkMotionAllUrara, allocator);
		document.AddMember("homeAllDiamond", Global->homeAllDiamond, allocator);
		document.AddMember("winMotion564", Global->winMotion564, allocator);


		rapidjson::Value dictArr(rapidjson::Type::kArrayType);

		for (const auto& s : dicts) {
			dictArr.PushBack(rapidjson::StringRef(s.c_str()), allocator);
		}
		document.AddMember("dicts", dictArr, allocator);

		// Save to file
		FILE* fp = fopen("config.json", "wb"); // non-Windows use "w"

		char writeBuffer[65536];
		rapidjson::FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));
		rapidjson::PrettyWriter<rapidjson::FileWriteStream> writer(os);
		document.Accept(writer);

		fclose(fp);
		return true;
	}
}