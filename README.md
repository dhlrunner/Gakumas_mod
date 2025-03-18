﻿# Gakumas_mod

Modding tool for the PC (DMM) version of the game Gakumas

## Features

- **IL2CPP Dump:** Press F8 to generate a dump file from IL2CPP. The dump.cs file will be generated in the modding DLL folder.
- **Unity Function Hooking:** Partial hooking of some Unity functions.
- **In-Game ImGUI Window:** Creates an ImGUI window within the game.
- **Future Enhancements:** More functionalities are planned to be added in upcoming updates.

## Installation

1. **Enable Developer Override:**  
   Open a console and run the following command:
   ```batch
   reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options" /v DevOverrideEnable /t REG_DWORD /d 1
   ```
2. **Reboot:**  
   Restart your PC to apply the registry change.
3. **Prepare Game Folder:**  
   In the folder containing `gakumas.exe`, create a new folder named `gakumas.exe.local`.
4. **Deploy the DLL:**  
   Copy the built `UnityPlayer.dll` from the project output into the newly created `gakumas.exe.local` folder.
5. **Launch the Game:**  
   Run Gakumasu from DMM Game Launcher to start the game with the mod enabled.

## Build Instructions

- **Development Environment:**  
  The project is developed and built using Visual Studio 2022.
- **Building the Project:**  
  Open the solution in VS2022 and build the project to generate the necessary `UnityPlayer.dll`.

## Notes

- This repository is based on the previous [Umamusume_mod](https://github.com/dhlrunner/Umamusume_mod) project, so some Umamusume related code may still be present.
- Ensure that your game version is compatible with this modding tool.

## Disclaimer

Use this mod at your own risk. The developers are not responsible for any potential damage or issues arising from its use.
