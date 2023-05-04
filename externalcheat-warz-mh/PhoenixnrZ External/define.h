#pragma warning(disable:4005)
#pragma warning(disable:4244)

#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>

#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <string.h>
#include <string>
#include <thread>
#include <chrono>
#include <map>
#include <list>

#include <WinUser.h>
#include <algorithm>
#include <array>
#include <dwmapi.h>
#include <vector>
#include <d3d9.h>   
#include <d3dx9.h>

#include <directxmath.h>
#include <codecvt>
#include <locale>
#include <atlbase.h>

#include <regex>

#include <psapi.h>
#include <sddl.h>
#include <accctrl.h>
#include <aclapi.h>

#pragma comment (lib, "Dwmapi.lib")
#pragma comment(lib, "psapi.lib")
#pragma comment (lib, "d3d9.lib") 
#pragma comment (lib, "d3dx9.lib")

#include "Vector.h"


extern HWND g_hWindow;
extern HMODULE hGameBase;