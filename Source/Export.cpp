#include <Windows.h>
#include <filesystem>
#include "hooks/Unity/UnityPlayer.hpp"


using namespace std;

extern "C" __declspec(dllexport) int __stdcall UnityMain(__int64 a1, __int64 a2, __int64 a3)
{
	try
	{
		
		copy_file(filesystem::current_path().append(L"UnityPlayer.dll"), L"gakumas.exe.local\\UnityPlayer.orig.dll", filesystem::copy_options::update_existing);
	}
	catch (const std::exception& e)
	{
		printf("Error: %s\n", e.what());
	}

	auto unity = LoadLibraryW(L"UnityPlayer.orig.dll");

	UnityMain_orig = GetProcAddress(unity, "UnityMain");

	return UnityMain_hook(a1, a2, a3);
}