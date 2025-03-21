﻿#pragma once
namespace Unity
{
	// Unity Structs
	// UnityEngine.Color
	struct Color_t
	{
	public:
		// System.Single UnityEngine.Color::r
		float r;
		// System.Single UnityEngine.Color::g
		float g;
		// System.Single UnityEngine.Color::b
		float b;
		// System.Single UnityEngine.Color::a
		float a;
	};

	// UnityEngine.Vector2
	struct Vector2_t
	{
	public:
		// System.Single UnityEngine.Vector2::x
		float x;
		// System.Single UnityEngine.Vector2::y
		float y;
	};

	struct Vector2_Int_t {
		int m_X;
		int m_Y;
	};


	// UnityEngine.Vector3
	struct Vector3_t
	{
	public:
		// System.Single UnityEngine.Vector3::x
		float x;
		// System.Single UnityEngine.Vector3::y
		float y;
		// System.Single UnityEngine.Vector3::z
		float z;
	};

	enum class FullScreenMode {
		ExclusiveFullScreen,
		FullScreenWindow,
		MaximizedWindow,
		Windowed
	};

	// UnityEngine.ScreenOrientation
	enum class ScreenOrientation {
		Unknown,
		Portrait,
		PortraitUpsideDown,
		LandscapeLeft,
		LandscapeRight,
		AutoRotation,
		Landscape = 3
	};

	struct LoadSceneParameters {
	public:
		int LoadSceneMode;
		int LocalPhysicsMode;
	};

	enum class KeyCode {
		None = 0,
		Backspace = 8,
		Tab = 9,
		Clear = 12, // 0x0000000C
		Return = 13, // 0x0000000D
		Pause = 19, // 0x00000013
		Escape = 27, // 0x0000001B
		Space = 32, // 0x00000020
		Exclaim = 33, // 0x00000021
		DoubleQuote = 34, // 0x00000022
		Hash = 35, // 0x00000023
		Dollar = 36, // 0x00000024
		Ampersand = 38, // 0x00000026
		Quote = 39, // 0x00000027
		LeftParen = 40, // 0x00000028
		RightParen = 41, // 0x00000029
		Asterisk = 42, // 0x0000002A
		Plus = 43, // 0x0000002B
		Comma = 44, // 0x0000002C
		Minus = 45, // 0x0000002D
		Period = 46, // 0x0000002E
		Slash = 47, // 0x0000002F
		Alpha0 = 48, // 0x00000030
		Alpha1 = 49, // 0x00000031
		Alpha2 = 50, // 0x00000032
		Alpha3 = 51, // 0x00000033
		Alpha4 = 52, // 0x00000034
		Alpha5 = 53, // 0x00000035
		Alpha6 = 54, // 0x00000036
		Alpha7 = 55, // 0x00000037
		Alpha8 = 56, // 0x00000038
		Alpha9 = 57, // 0x00000039
		Colon = 58, // 0x0000003A
		Semicolon = 59, // 0x0000003B
		Less = 60, // 0x0000003C
		Equals = 61, // 0x0000003D
		Greater = 62, // 0x0000003E
		Question = 63, // 0x0000003F
		At = 64, // 0x00000040
		LeftBracket = 91, // 0x0000005B
		Backslash = 92, // 0x0000005C
		RightBracket = 93, // 0x0000005D
		Caret = 94, // 0x0000005E
		Underscore = 95, // 0x0000005F
		BackQuote = 96, // 0x00000060
		A = 97, // 0x00000061
		B = 98, // 0x00000062
		C = 99, // 0x00000063
		D = 100, // 0x00000064
		E = 101, // 0x00000065
		F = 102, // 0x00000066
		G = 103, // 0x00000067
		H = 104, // 0x00000068
		I = 105, // 0x00000069
		J = 106, // 0x0000006A
		K = 107, // 0x0000006B
		L = 108, // 0x0000006C
		M = 109, // 0x0000006D
		N = 110, // 0x0000006E
		O = 111, // 0x0000006F
		P = 112, // 0x00000070
		Q = 113, // 0x00000071
		R = 114, // 0x00000072
		S = 115, // 0x00000073
		T = 116, // 0x00000074
		U = 117, // 0x00000075
		V = 118, // 0x00000076
		W = 119, // 0x00000077
		X = 120, // 0x00000078
		Y = 121, // 0x00000079
		Z = 122, // 0x0000007A
		Delete = 127, // 0x0000007F
		Keypad0 = 256, // 0x00000100
		Keypad1 = 257, // 0x00000101
		Keypad2 = 258, // 0x00000102
		Keypad3 = 259, // 0x00000103
		Keypad4 = 260, // 0x00000104
		Keypad5 = 261, // 0x00000105
		Keypad6 = 262, // 0x00000106
		Keypad7 = 263, // 0x00000107
		Keypad8 = 264, // 0x00000108
		Keypad9 = 265, // 0x00000109
		KeypadPeriod = 266, // 0x0000010A
		KeypadDivide = 267, // 0x0000010B
		KeypadMultiply = 268, // 0x0000010C
		KeypadMinus = 269, // 0x0000010D
		KeypadPlus = 270, // 0x0000010E
		KeypadEnter = 271, // 0x0000010F
		KeypadEquals = 272, // 0x00000110
		UpArrow = 273, // 0x00000111
		DownArrow = 274, // 0x00000112
		RightArrow = 275, // 0x00000113
		LeftArrow = 276, // 0x00000114
		Insert = 277, // 0x00000115
		Home = 278, // 0x00000116
		End = 279, // 0x00000117
		PageUp = 280, // 0x00000118
		PageDown = 281, // 0x00000119
		F1 = 282, // 0x0000011A
		F2 = 283, // 0x0000011B
		F3 = 284, // 0x0000011C
		F4 = 285, // 0x0000011D
		F5 = 286, // 0x0000011E
		F6 = 287, // 0x0000011F
		F7 = 288, // 0x00000120
		F8 = 289, // 0x00000121
		F9 = 290, // 0x00000122
		F10 = 291, // 0x00000123
		F11 = 292, // 0x00000124
		F12 = 293, // 0x00000125
		F13 = 294, // 0x00000126
		F14 = 295, // 0x00000127
		F15 = 296, // 0x00000128
		Numlock = 300, // 0x0000012C
		CapsLock = 301, // 0x0000012D
		ScrollLock = 302, // 0x0000012E
		RightShift = 303, // 0x0000012F
		LeftShift = 304, // 0x00000130
		RightControl = 305, // 0x00000131
		LeftControl = 306, // 0x00000132
		RightAlt = 307, // 0x00000133
		LeftAlt = 308, // 0x00000134
		RightApple = 309, // 0x00000135
		RightCommand = 309, // 0x00000135
		LeftApple = 310, // 0x00000136
		LeftCommand = 310, // 0x00000136
		LeftWindows = 311, // 0x00000137
		RightWindows = 312, // 0x00000138
		AltGr = 313, // 0x00000139
		Help = 315, // 0x0000013B
		Print = 316, // 0x0000013C
		SysReq = 317, // 0x0000013D
		Break = 318, // 0x0000013E
		Menu = 319, // 0x0000013F
		Mouse0 = 323, // 0x00000143
		Mouse1 = 324, // 0x00000144
		Mouse2 = 325, // 0x00000145
		Mouse3 = 326, // 0x00000146
		Mouse4 = 327, // 0x00000147
		Mouse5 = 328, // 0x00000148
		Mouse6 = 329, // 0x00000149
		JoystickButton0 = 330, // 0x0000014A
		JoystickButton1 = 331, // 0x0000014B
		JoystickButton2 = 332, // 0x0000014C
		JoystickButton3 = 333, // 0x0000014D
		JoystickButton4 = 334, // 0x0000014E
		JoystickButton5 = 335, // 0x0000014F
		JoystickButton6 = 336, // 0x00000150
		JoystickButton7 = 337, // 0x00000151
		JoystickButton8 = 338, // 0x00000152
		JoystickButton9 = 339, // 0x00000153
		JoystickButton10 = 340, // 0x00000154
		JoystickButton11 = 341, // 0x00000155
		JoystickButton12 = 342, // 0x00000156
		JoystickButton13 = 343, // 0x00000157
		JoystickButton14 = 344, // 0x00000158
		JoystickButton15 = 345, // 0x00000159
		JoystickButton16 = 346, // 0x0000015A
		JoystickButton17 = 347, // 0x0000015B
		JoystickButton18 = 348, // 0x0000015C
		JoystickButton19 = 349, // 0x0000015D
		Joystick1Button0 = 350, // 0x0000015E
		Joystick1Button1 = 351, // 0x0000015F
		Joystick1Button2 = 352, // 0x00000160
		Joystick1Button3 = 353, // 0x00000161
		Joystick1Button4 = 354, // 0x00000162
		Joystick1Button5 = 355, // 0x00000163
		Joystick1Button6 = 356, // 0x00000164
		Joystick1Button7 = 357, // 0x00000165
		Joystick1Button8 = 358, // 0x00000166
		Joystick1Button9 = 359, // 0x00000167
		Joystick1Button10 = 360, // 0x00000168
		Joystick1Button11 = 361, // 0x00000169
		Joystick1Button12 = 362, // 0x0000016A
		Joystick1Button13 = 363, // 0x0000016B
		Joystick1Button14 = 364, // 0x0000016C
		Joystick1Button15 = 365, // 0x0000016D
		Joystick1Button16 = 366, // 0x0000016E
		Joystick1Button17 = 367, // 0x0000016F
		Joystick1Button18 = 368, // 0x00000170
		Joystick1Button19 = 369, // 0x00000171
		Joystick2Button0 = 370, // 0x00000172
		Joystick2Button1 = 371, // 0x00000173
		Joystick2Button2 = 372, // 0x00000174
		Joystick2Button3 = 373, // 0x00000175
		Joystick2Button4 = 374, // 0x00000176
		Joystick2Button5 = 375, // 0x00000177
		Joystick2Button6 = 376, // 0x00000178
		Joystick2Button7 = 377, // 0x00000179
		Joystick2Button8 = 378, // 0x0000017A
		Joystick2Button9 = 379, // 0x0000017B
		Joystick2Button10 = 380, // 0x0000017C
		Joystick2Button11 = 381, // 0x0000017D
		Joystick2Button12 = 382, // 0x0000017E
		Joystick2Button13 = 383, // 0x0000017F
		Joystick2Button14 = 384, // 0x00000180
		Joystick2Button15 = 385, // 0x00000181
		Joystick2Button16 = 386, // 0x00000182
		Joystick2Button17 = 387, // 0x00000183
		Joystick2Button18 = 388, // 0x00000184
		Joystick2Button19 = 389, // 0x00000185
		Joystick3Button0 = 390, // 0x00000186
		Joystick3Button1 = 391, // 0x00000187
		Joystick3Button2 = 392, // 0x00000188
		Joystick3Button3 = 393, // 0x00000189
		Joystick3Button4 = 394, // 0x0000018A
		Joystick3Button5 = 395, // 0x0000018B
		Joystick3Button6 = 396, // 0x0000018C
		Joystick3Button7 = 397, // 0x0000018D
		Joystick3Button8 = 398, // 0x0000018E
		Joystick3Button9 = 399, // 0x0000018F
		Joystick3Button10 = 400, // 0x00000190
		Joystick3Button11 = 401, // 0x00000191
		Joystick3Button12 = 402, // 0x00000192
		Joystick3Button13 = 403, // 0x00000193
		Joystick3Button14 = 404, // 0x00000194
		Joystick3Button15 = 405, // 0x00000195
		Joystick3Button16 = 406, // 0x00000196
		Joystick3Button17 = 407, // 0x00000197
		Joystick3Button18 = 408, // 0x00000198
		Joystick3Button19 = 409, // 0x00000199
		Joystick4Button0 = 410, // 0x0000019A
		Joystick4Button1 = 411, // 0x0000019B
		Joystick4Button2 = 412, // 0x0000019C
		Joystick4Button3 = 413, // 0x0000019D
		Joystick4Button4 = 414, // 0x0000019E
		Joystick4Button5 = 415, // 0x0000019F
		Joystick4Button6 = 416, // 0x000001A0
		Joystick4Button7 = 417, // 0x000001A1
		Joystick4Button8 = 418, // 0x000001A2
		Joystick4Button9 = 419, // 0x000001A3
		Joystick4Button10 = 420, // 0x000001A4
		Joystick4Button11 = 421, // 0x000001A5
		Joystick4Button12 = 422, // 0x000001A6
		Joystick4Button13 = 423, // 0x000001A7
		Joystick4Button14 = 424, // 0x000001A8
		Joystick4Button15 = 425, // 0x000001A9
		Joystick4Button16 = 426, // 0x000001AA
		Joystick4Button17 = 427, // 0x000001AB
		Joystick4Button18 = 428, // 0x000001AC
		Joystick4Button19 = 429, // 0x000001AD
		Joystick5Button0 = 430, // 0x000001AE
		Joystick5Button1 = 431, // 0x000001AF
		Joystick5Button2 = 432, // 0x000001B0
		Joystick5Button3 = 433, // 0x000001B1
		Joystick5Button4 = 434, // 0x000001B2
		Joystick5Button5 = 435, // 0x000001B3
		Joystick5Button6 = 436, // 0x000001B4
		Joystick5Button7 = 437, // 0x000001B5
		Joystick5Button8 = 438, // 0x000001B6
		Joystick5Button9 = 439, // 0x000001B7
		Joystick5Button10 = 440, // 0x000001B8
		Joystick5Button11 = 441, // 0x000001B9
		Joystick5Button12 = 442, // 0x000001BA
		Joystick5Button13 = 443, // 0x000001BB
		Joystick5Button14 = 444, // 0x000001BC
		Joystick5Button15 = 445, // 0x000001BD
		Joystick5Button16 = 446, // 0x000001BE
		Joystick5Button17 = 447, // 0x000001BF
		Joystick5Button18 = 448, // 0x000001C0
		Joystick5Button19 = 449, // 0x000001C1
		Joystick6Button0 = 450, // 0x000001C2
		Joystick6Button1 = 451, // 0x000001C3
		Joystick6Button2 = 452, // 0x000001C4
		Joystick6Button3 = 453, // 0x000001C5
		Joystick6Button4 = 454, // 0x000001C6
		Joystick6Button5 = 455, // 0x000001C7
		Joystick6Button6 = 456, // 0x000001C8
		Joystick6Button7 = 457, // 0x000001C9
		Joystick6Button8 = 458, // 0x000001CA
		Joystick6Button9 = 459, // 0x000001CB
		Joystick6Button10 = 460, // 0x000001CC
		Joystick6Button11 = 461, // 0x000001CD
		Joystick6Button12 = 462, // 0x000001CE
		Joystick6Button13 = 463, // 0x000001CF
		Joystick6Button14 = 464, // 0x000001D0
		Joystick6Button15 = 465, // 0x000001D1
		Joystick6Button16 = 466, // 0x000001D2
		Joystick6Button17 = 467, // 0x000001D3
		Joystick6Button18 = 468, // 0x000001D4
		Joystick6Button19 = 469, // 0x000001D5
		Joystick7Button0 = 470, // 0x000001D6
		Joystick7Button1 = 471, // 0x000001D7
		Joystick7Button2 = 472, // 0x000001D8
		Joystick7Button3 = 473, // 0x000001D9
		Joystick7Button4 = 474, // 0x000001DA
		Joystick7Button5 = 475, // 0x000001DB
		Joystick7Button6 = 476, // 0x000001DC
		Joystick7Button7 = 477, // 0x000001DD
		Joystick7Button8 = 478, // 0x000001DE
		Joystick7Button9 = 479, // 0x000001DF
		Joystick7Button10 = 480, // 0x000001E0
		Joystick7Button11 = 481, // 0x000001E1
		Joystick7Button12 = 482, // 0x000001E2
		Joystick7Button13 = 483, // 0x000001E3
		Joystick7Button14 = 484, // 0x000001E4
		Joystick7Button15 = 485, // 0x000001E5
		Joystick7Button16 = 486, // 0x000001E6
		Joystick7Button17 = 487, // 0x000001E7
		Joystick7Button18 = 488, // 0x000001E8
		Joystick7Button19 = 489, // 0x000001E9
		Joystick8Button0 = 490, // 0x000001EA
		Joystick8Button1 = 491, // 0x000001EB
		Joystick8Button2 = 492, // 0x000001EC
		Joystick8Button3 = 493, // 0x000001ED
		Joystick8Button4 = 494, // 0x000001EE
		Joystick8Button5 = 495, // 0x000001EF
		Joystick8Button6 = 496, // 0x000001F0
		Joystick8Button7 = 497, // 0x000001F1
		Joystick8Button8 = 498, // 0x000001F2
		Joystick8Button9 = 499, // 0x000001F3
		Joystick8Button10 = 500, // 0x000001F4
		Joystick8Button11 = 501, // 0x000001F5
		Joystick8Button12 = 502, // 0x000001F6
		Joystick8Button13 = 503, // 0x000001F7
		Joystick8Button14 = 504, // 0x000001F8
		Joystick8Button15 = 505, // 0x000001F9
		Joystick8Button16 = 506, // 0x000001FA
		Joystick8Button17 = 507, // 0x000001FB
		Joystick8Button18 = 508, // 0x000001FC
		Joystick8Button19 = 509, // 0x000001FD
	};

	struct RefreshRate
	{
	public:
		unsigned int numerator;
		unsigned int denominator;
		unsigned int value;
	};

	struct Resolution_t
	{
	public:
		int32_t width;
		int32_t height;
		int32_t herz;
		char _stackDummy[1024]; //이거 안하면 stack around the variable was corrupted 에러남
	};
}