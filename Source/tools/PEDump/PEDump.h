#pragma once
#include <string>
#include <windows.h>
#include <psapi.h>
#include <vector>

void pedump(HMODULE mod, const std::string& name);