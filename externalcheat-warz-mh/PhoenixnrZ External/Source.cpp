#include "define.h"
#include "Overlay.h"
#include "Xorstr.h"
#include<cstdio>
#include <ShObjIdl.h>

//class r3dRenderLayer* pRenderer = NULL;
DWORD InstallHook()
{

	//เปิดnhz /550

	/*Sleep(4000);*/


	//char wnd_title[256];
	////HWND foreground = GetForegroundWindow();
	//for (;;)
	//{
	//	DWORD procid;
	//	MessageBox(0, "กด OK เมื่ออยู่หน้าเลือกตัวละคร", " ", MB_OK | MB_ICONINFORMATION);
	//	HWND windows = FindWindowA(("r3dWin"), 0); // ชื่อ คลาสของตัวเกมส์
	//	DWORD actualProcID = GetWindowThreadProcessId(windows, &procid);
	//	{
	//		g_hWindow = windows;
	//		break;
	//	}
	//	std::this_thread::sleep_for(
	//		std::chrono::milliseconds(250));
	//}
	class r3dRenderLayer* pRenderer = NULL;
	//สำหรับtitle
	MessageBox(0, "กด OK เมื่ออยู่หน้าเลือกตัวละคร", " ", MB_OK | MB_ICONINFORMATION);
	char wnd_title[256];
	HWND foreground = GetForegroundWindow();
	for (;;)
	{
		foreground = GetForegroundWindow();
		GetWindowTextA(foreground, wnd_title, sizeof(wnd_title));
		if (strstr(wnd_title, "WaiHnumZ - PvP | FarM")) // WaiHnumZ - PvP | FarM
		{
			g_hWindow = foreground;
			break;
		}
		std::this_thread::sleep_for(
			std::chrono::milliseconds(550));
	}


	Beep(800, 500);

	//AllocConsole();
	//SetConsoleTitle("Debug Console");

	//freopen("CONOUT$", "wb", stdout);
	//freopen("CONOUT$", "wb", stderr);

	//EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE, MF_GRAYED);
	//
	return NULL;
}


//DWORD InstallHook()
//{
//
//
//
//	Sleep(4000);
//
//
//	char wnd_title[256];
//	HWND foreground = GetForegroundWindow();
//	for (;;)
//	{
//		foreground = GetForegroundWindow();
//		GetWindowTextA(foreground, wnd_title, sizeof(wnd_title));
//		if (strstr(wnd_title, "Undoz")) // v1.6.0  (CARMELZ FREE TO PLAY v1.1.5) - final) - final) - final
//		{
//			g_hWindow = foreground;
//			break;
//		}
//		std::this_thread::sleep_for(
//			std::chrono::milliseconds(550));
//	}
//
//
//	Beep(800, 500);
//	
//	//AllocConsole();
//	//SetConsoleTitle("Debug Console");
//
//	//freopen("CONOUT$", "wb", stdout);
//	//freopen("CONOUT$", "wb", stderr);
//
//	//EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE, MF_GRAYED);
//	//
//	return NULL;
//}

//using namespace std;
//vector<string> serial;

//void OVx0vHNN3AyNXcPABPNL8pVkQDmTokz6()
//{
//	serial.push_back(/*2157920119*/XorStr<0xA5, 11, 0x6F54B95B>("\x97\x97\x92\x9F\x90\x98\x9B\x9D\x9C\x97" + 0x6F54B95B).s);  // M HD 
//	serial.push_back(/*840147247*/XorStr<0x81, 10, 0x8C816EF8>("\xB9\xB6\xB3\xB5\xB1\xB1\xB5\xBC\xBE" + 0x8C816EF8).s);  // นน  
//	serial.push_back(/*3260575700*/XorStr<0xB8,11,0x28329EC9>("\x8B\x8B\x8C\x8B\x89\x8A\x8B\x88\xF0\xF1"+0x28329EC9).s);
//	serial.push_back(/*3994850170*/XorStr<0xA6, 11, 0xB94CA08F>("\x95\x9E\x91\x9D\x92\x9E\x9C\x9C\x99\x9F" + 0xB94CA08F).s); // 1 วัน
//}


//void PGxE5pH040Wd8xbJwQXRqeLtilJwHvkz()
//{
//	OVx0vHNN3AyNXcPABPNL8pVkQDmTokz6();
//
//	TCHAR volumeName[MAX_PATH + 1] = { 0 };
//	TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
//	DWORD serialNumber = 0;
//	DWORD maxComponentLen = 0;
//	DWORD fileSystemFlags = 0;
//
//	if (GetVolumeInformation(("C:\\"), volumeName, ARRAYSIZE(volumeName), &serialNumber, &maxComponentLen, &fileSystemFlags, fileSystemName, ARRAYSIZE(fileSystemName)));
//
//
//	if (find(serial.begin(), serial.end(), to_string(serialNumber)) != serial.end())
//	{
//		//cHzSJiY0pKe5wYMAu4gBQkRH85oOMFp0();
//	}
//	else
//	{
//		MessageBox(0, /*Hwid Not valid !*/XorStr<0x97, 17, 0x64BE9511>("\xDF\xEF\xF0\xFE\xBB\xD2\xF2\xEA\xBF\xD6\xC0\xCE\xCA\xC0\x85\x87" + 0x64BE9511).s, /*ErrorMessagebox*/XorStr<0xF8, 16, 0xE091E32D>("\xBD\x8B\x88\x94\x8E\xB0\x9B\x8C\x73\x60\x65\x66\x66\x6A\x7E" + 0xE091E32D).s, MB_ICONERROR);
//		ExitProcess(1);
//	}
//}

DWORD dwGetProcessID(PCHAR szProcName) {
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	DWORD dwGetProcessID = 0;
	if (hSnapshot != INVALID_HANDLE_VALUE) {
		PROCESSENTRY32 ProcEntry32 = { 0 };
		ProcEntry32.dwSize = sizeof(MODULEENTRY32);
		if (Process32First(hSnapshot, &ProcEntry32)) {
			do {
				if (strcmp(ProcEntry32.szExeFile, szProcName) == 0) {
					dwGetProcessID = (DWORD)ProcEntry32.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnapshot, &ProcEntry32));
		}
		CloseHandle(hSnapshot);
	}
	return dwGetProcessID;//2004
}

DWORD killProcessByName(const char* filename)
{
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
	PROCESSENTRY32 pEntry;
	DWORD dwGetProcessID = 0;
	pEntry.dwSize = sizeof(pEntry);
	BOOL hRes = Process32First(hSnapShot, &pEntry);
	while (hRes)
	{
		if (strcmp(pEntry.szExeFile, filename) == 0)
		{
			HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0, (DWORD)pEntry.th32ProcessID);
			if (hProcess != NULL)
			{
				dwGetProcessID = TerminateProcess(hProcess, 9);
				CloseHandle(hProcess);
			}
		}
		hRes = Process32Next(hSnapShot, &pEntry);
	}
	CloseHandle(hSnapShot);
	return dwGetProcessID;
}

bool XXDDW = false;
DWORD TEST()
{
	do
	{
		DWORD dwPID = dwGetProcessID("ZGxReports.exe");

		if (dwPID)
		{
			killProcessByName("ZGxReports.exe");
		}

	} while (!XXDDW);

	return 1;
}


DWORD WINAPI Delete(LPVOID)
{
	TEST();

	return 0L;
}


DWORD WINAPI MainThread(LPVOID hModule)
{


	InstallHook();
	Overlay::GetInstance()->WinMain(HINSTANCE(), NULL, NULL, NULL);
	return 0;
}

extern __declspec(dllexport)void WINAPI OnDllAttach(LPVOID pParam)
{
}

bool _stdcall DllMain(HMODULE hModule, std::uintptr_t uReason, void* lpReserved)
{
	if (uReason == DLL_PROCESS_ATTACH)
	{
		///AllocConsole();
		hGameBase = GetModuleHandleA(NULL);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)OnDllAttach, hModule, 0, 0);
		CreateThread(NULL, NULL, MainThread, hModule, NULL, nullptr);
		//CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Delete, hModule, 0, 0);
	}

	return true;
}