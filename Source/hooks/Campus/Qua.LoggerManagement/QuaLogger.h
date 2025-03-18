#pragma once

#include "../../tools/Logger.hpp"
#include "../../Unity/il2cpp/il2cpp-api-types.h"
#include "../../Unity/il2cpp/il2cpp-object-internals.h"
#include "../../Unity/il2cpp/il2cpp_symbols.hpp"
#include "../../Utils.h"
#include "../../hook-helper.h"

#define SECTION_NAME L"QUALOGGER"

namespace Qua::LoggerManagement::Logger_::QuaLogger
{
	void Init();
}