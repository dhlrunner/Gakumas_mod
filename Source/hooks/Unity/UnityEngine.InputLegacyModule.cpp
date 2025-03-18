#include "UnityEngine.InputLegacyModule.h"

namespace UnityEngine::InputLegacyModule
{
	bool (*GetKeyDown)(KeyCode);
	bool (*GetKey)(KeyCode);

	void Init() 
	{
		GetKeyDown = reinterpret_cast<bool(*)(KeyCode)> (
			il2cpp_symbols::get_method_pointer(
				"UnityEngine.InputLegacyModule.dll", "UnityEngine",
				"Input", "GetKeyDown", 1
			)
			);

		GetKey = reinterpret_cast<bool(*)(KeyCode)> (
			il2cpp_symbols::get_method_pointer(
				"UnityEngine.InputLegacyModule.dll", "UnityEngine",
				"Input", "GetKey", 1
			)
			);
	}
}