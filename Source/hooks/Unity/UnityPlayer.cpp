#include "UnityPlayer.hpp"

void* UnityMain_orig = nullptr;
int __stdcall UnityMain_hook(__int64 a1, __int64 a2, __int64 a3)
{
	Logger::Debug(L"UNITYPLAYER", L"UnityMain_hook(%p, %p, %p)", a1, a2, a3);
	return reinterpret_cast<decltype(UnityMain_hook)*>(UnityMain_orig)(a1, a2, a3);
}

