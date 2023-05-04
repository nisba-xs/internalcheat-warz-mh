/**
* Knight Project
* Copyright (c) 2017 DaRkWoRlD
* MemoryThread.cpp
*/


#pragma once

#include "define.h"

extern std::ofstream dumpFile;

std::wstring GetExecutableDirectory();
std::wstring GetFileDirectory(const std::wstring& fileName);
std::wstring GetRelativeFilePath(const std::wstring& directory, const std::wstring& fileName); 
void PrintFormat(const char* format, ...);
void PrintWFormat(const wchar_t* format, ...);
void Log(std::string line);
std::string TextFormat(const char* format, ...);
std::wstring TextWFormat(const wchar_t* format, ...);
uint32_t GetProcessIdByName(const std::wstring& processName);
POINT GetWindowPosition(HWND hWindow);
POINT GetWindowSize(HWND hWindow);
VOID ShowConsole();
float MathDistance(Vector3 a, Vector3 b);
BOOL DataCompare(BYTE* pData, BYTE* bMask, char* szMask);
DWORD FindPattern(HMODULE hModule, DWORD dwLen, BYTE* bMask, char* szMask, DWORD offset = 0);
DWORD FindSignature(const char* szModuleName, char* szPattern);