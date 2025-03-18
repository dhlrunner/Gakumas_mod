#define _CRT_SECURE_NO_WARNINGS 1

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include "hooks/hook.h"

#include "deps/minhook/include/MinHook.h"
#pragma comment(lib, "lib/Debug/libMinHook.x64.lib")

using namespace std;

void CreateConsole()
{
	if (!AttachConsole(ATTACH_PARENT_PROCESS)) {
		if (!AllocConsole()) {
			MessageBox(NULL, L"Failed to allocate console", L"Error", MB_OK | MB_ICONERROR);
			return;
		}
	}

	//open stdout stream
	auto _ = freopen("CONOUT$", "w", stdout);
	_ = freopen("CONOUT$", "w", stderr);
	_ = freopen("CONIN$", "r", stdin);
	
	SetConsoleTitle(L"Gakumasu - Debug Console");

	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hInput, ENABLE_VIRTUAL_TERMINAL_INPUT);
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleMode(hOutput, ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	// set this to avoid turn japanese texts into question mark
	SetConsoleOutputCP(CP_UTF8);
	//_setmode(_fileno(stdout), _O_U16TEXT);
	std::locale::global(std::locale(""));

}

BOOL WINAPI DllMain(HINSTANCE, DWORD reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH) {		
		Logger::Info(L"HOOK", L"Modding DLL Attatched");
		CreateConsole();
		InitHooks_DLLMain();
		return TRUE;
	}
	else if (reason == DLL_PROCESS_DETACH) {
		Logger::Info(L"HOOK", L"Modding DLL Detatching");
		MH_Uninitialize();
	}

	return TRUE;
}