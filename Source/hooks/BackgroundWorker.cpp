#include "BackgroundWorker.h"

using namespace std;
using namespace UnityEngine::InputLegacyModule;
using namespace UnityEngine::CoreModule;
using namespace Global;

namespace BackgroundWorker
{
	

	void keyDownCheckThread() {
		Logger::Debug(SECTION_NAME, L"KeyDownCheckThread IN!!!");

		while (true) {
			bool ret = GetKeyDown(KeyCode::S); //S
			bool ctrl = GetKey(KeyCode::LeftControl); //LCtrl
			bool alt = GetKey(KeyCode::LeftAlt);
			bool f12 = GetKeyDown(KeyCode::F12);
			bool f10 = GetKeyDown(KeyCode::F10);
			bool f11 = GetKeyDown(KeyCode::F11);
			bool f9 = GetKeyDown(KeyCode::F9);
			bool f8 = GetKeyDown(KeyCode::F8);
			bool f7 = GetKeyDown(KeyCode::F7);
			if (f12) {
				printf("F12 is Pressed!!!!\n");
				while (GetKeyDown(KeyCode::F12)) {}
				imgui_settingwnd_open = !imgui_settingwnd_open;
				printf("Show setting screen \n");
			}
			if (f8) {
				printf("Dump il2cpp start");
				while (GetKeyDown(KeyCode::F8)) {}
				//auto dialog = GallopDialog::ShowTextDialog(L"Dump il2cpp", L"Please wait...", false);
				auto h = GetModuleHandle(L"GameAssembly.dll");
				//GallopDialog::SetDialogMessage(dialog, L"Dumping GameAssembly.dll ...");
				pedump(h, "gakumas.exe.local\\GameAssembly.dumped.dll");
				il2cpp_dump();
				Sleep(1000);
				//GallopDialog::CloseDialog(dialog);
			}
			if (f10) {
				printf("F10 is Pressed!!!!\n");
				while (GetKeyDown(KeyCode::F10)) {}
				Settings::Global->isShowLivePerfInfo = !Settings::Global->isShowLivePerfInfo;
				//printf("%d\n", Settings::Global->isShowLivePerfInfo);
			}
			
			if (gameTerminating) 
			{
				Logger::Debug(SECTION_NAME, L"Game Terminating.. Exit loop");
				break;
			}
		}
	}

	void Update() 
	{
		Logger::Debug(SECTION_NAME, L"Update thread in");
		while (!gameTerminating) 
		{
			
		}

		Logger::Info(SECTION_NAME, L"Exit update thread");

	}

	void Init()
	{
		Logger::Info(SECTION_NAME, L"Init");
		Logger::Info(SECTION_NAME, L"Starting thread");

		auto t1 = thread([]() {
			auto tr = il2cpp_thread_attach(il2cpp_domain_get());
			keyDownCheckThread();
			il2cpp_thread_detach(tr);
		});
		
		Logger::Info(SECTION_NAME, L"Thread ID: %d", t1.get_id());
		t1.detach();

		auto t2 = thread([]() {
			auto tr = il2cpp_thread_attach(il2cpp_domain_get());
			Update();
			il2cpp_thread_detach(tr);
		});
		Logger::Info(SECTION_NAME, L"Thread ID: %d", t2.get_id());
		t2.detach();
	}
}