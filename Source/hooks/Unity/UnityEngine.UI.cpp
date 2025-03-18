#include "UnityEngine.UI.h"

namespace UnityEngine::UI
{
	void (*set_scaleFactor)(void*, float);


	void Init() 
	{
		set_scaleFactor = reinterpret_cast<void(*)(void*, float)>(
			il2cpp_symbols::get_method_pointer(
				"UnityEngine.UI.dll", "UnityEngine.UI",
				"CanvasScaler", "set_scaleFactor", 1
			)
		);
	}
}