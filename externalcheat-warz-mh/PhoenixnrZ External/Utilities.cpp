/**
* Knight Project
* Copyright (c) 2017 DaRkWoRlD
* MemoryThread.cpp
*/

#pragma once

#include "define.h"
#include "Utilities.h"
 

std::ofstream dumpFile;
std::wstring GetFileDirectory(const std::wstring& fileName)
{
	std::wstring result = std::wstring(fileName);

	return result.substr(0, result.find_last_of((L"\\/")));
}

std::wstring GetRelativeFilePath(const std::wstring& directory, const std::wstring& fileName)
{
	return std::wstring(directory).append((L"\\")).append(fileName);
}
 
void PrintFormat(const char* format, ...)
{
	va_list argptr;
	va_start(argptr, format);

	vprintf(format, argptr);

	va_end(argptr);
}

void PrintWFormat(const wchar_t* format, ...)
{
	va_list argptr;
	va_start(argptr, format);

	vwprintf(format, argptr);

	va_end(argptr);
}

void Log(std::string line)
{  
	dumpFile << "[LOG] " << line << std::endl; 
	dumpFile.flush();
}

std::string TextFormat(const char* format, ...)
{
	va_list argptr;
	va_start(argptr, format);

	char buffer[2048];
	vsprintf(buffer, format, argptr);

	va_end(argptr);

	return buffer;
}

std::wstring TextWFormat(const wchar_t* format, ...)
{
	va_list argptr;
	va_start(argptr, format);

	wchar_t buffer[2048];
	_vswprintf(buffer, format, argptr);

	va_end(argptr);

	return buffer;
}
POINT GetWindowSize(HWND hWindow)
{
	RECT rc;
	POINT result;
	GetWindowRect(hWindow, &rc);

	result.x = rc.right - rc.left;
	result.y = rc.bottom - rc.top;
	 
	result.y -= 25/2;
	return result;
}
POINT GetWindowPosition(HWND hWindow)
{
	RECT rc;
	POINT result;
	GetWindowRect(hWindow, &rc);

	result.x = rc.left;
	result.y = rc.top;

	result.y += 25;
	return result;
}
VOID ShowConsole()
{
	AllocConsole();
	SetConsoleTitle("Debug Console");

	freopen("CONOUT$", "wb", stdout);
	freopen("CONOUT$", "wb", stderr);

	EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE, MF_GRAYED); 
}

float MathDistance(Vector3 a, Vector3 b)
{
	return sqrt(
		powf(a.x - b.x, 2.0) +
		powf(a.y - b.y, 2.0) +
		powf(a.z - b.z, 2.0));
};

BOOL DataCompare(BYTE* pData, BYTE* bMask, char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++bMask)
		if (*szMask == 'x' && *pData != *bMask)
			return FALSE;

	return (*szMask == NULL);
}

DWORD FindPattern(HMODULE hModule, DWORD dwLen, BYTE* bMask, char* szMask, DWORD offset)
{
	DWORD dwAddress = (DWORD)hModule + 0x1000/*codebase*/;

	if (dwLen == 0)
	{
		MODULEINFO mi = { 0 };
		GetModuleInformation(GetCurrentProcess(), (hModule ? hModule : GetModuleHandle(NULL)), &mi, sizeof(mi));

		dwLen = mi.SizeOfImage - 0x1000/*codebase*/;
	}

	for (DWORD i = 0; i < dwLen; i++)
	{
		if (IsBadReadPtr((void*)(dwAddress + i), 4) == 0 && DataCompare((BYTE*)(dwAddress + i), bMask, szMask))
		{
			return (DWORD)(dwAddress + i + offset);
		}
	}

	return 0;
}
