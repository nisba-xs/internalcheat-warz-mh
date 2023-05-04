/**
* Knight Project
* Copyright (c) 2017 DaRkWoRlD
* MemoryThread.cpp
*/

#pragma once
#include <ShObjIdl.h>
#include "Overlay.h" 
#include "Utilities.h"
#include "Renderer.h"

HWND g_hWindow = NULL;
HMODULE hGameBase = NULL;

/*
#include "..\MemoryThread.h"
#include "..\DXRenderer.h"
#include "..\HookManager.h"

#include "..\ImGui\imgui.h"
#include "..\ImGui\imgui_impl_dx9.h"
*/

#define assert(_Expression) Log(TextFormat("ASSERT at file %s, line %d: %s\n", __FILE__, __LINE__, _Expression))

Overlay* Overlay::m_pInstance;
RECT tSize;

char *							Overlay::targetWindowName;
HWND							Overlay::targetWindow;
HWND							Overlay::overlayWindow;
MARGINS							Overlay::windowMargin;
float							Overlay::overlaySize[2];

IDirect3DDevice9Ex*				Overlay::pDevice;
ID3DXFont*						Overlay::pFont;
IDirect3D9Ex*					Overlay::pObject;
ID3DXLine*						Overlay::pLine;
D3DPRESENT_PARAMETERS			Overlay::pParams;

MSG windowMessage; 
Overlay::Overlay()
{
	targetWindowName = "Tencent*!";
	windowMargin = { -1, -1, -1, -1 };
	targetWindow = HWND();
	overlayWindow = HWND(); 
}

Overlay::~Overlay()
{

}

long _stdcall Overlay::WindowProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch (Message)
	{
	case WM_PAINT: 
		PickupDraw();
		break;

	case WM_CREATE:
		break;

	case WM_DESTROY:
		//assert("destroy");
		PostQuitMessage(EXIT_FAILURE);
		return 0;

	default:
		return DefWindowProcA(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;
}
 

DWORD Overlay::D3D9XInit(HWND hWnd)
{
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &pObject)))
		exit(EXIT_FAILURE);
	

	ZeroMemory(&pParams, sizeof(pParams));
	pParams.Windowed = TRUE;
	pParams.SwapEffect = D3DSWAPEFFECT_DISCARD;
	pParams.hDeviceWindow = hWnd;
	pParams.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	pParams.BackBufferFormat = D3DFMT_A8R8G8B8;
	pParams.BackBufferWidth = overlaySize[0];
	pParams.BackBufferHeight = overlaySize[1];
	pParams.EnableAutoDepthStencil = TRUE;
	pParams.AutoDepthStencilFormat = D3DFMT_D16;

	if (FAILED(pObject->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &pParams, NULL, &pDevice)))
	{
		//Log("CreateDeviceEx");
		exit(EXIT_FAILURE);
	}
	//if (!pLine)
	//	D3DXCreateLine(pDevice, &pLine);
	
		//D3DXCreateFontA(pDevice, 18, 0, 0, 0, false, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "Calibri", &pFont);

	return EXIT_SUCCESS;
}

DWORD ProtectThread(void)
{
	HANDLE hProcess = GetCurrentThread();
	PACL pEmptyDacl;
	DWORD dwErr;

	// using malloc guarantees proper alignment
	pEmptyDacl = (PACL)malloc(sizeof(ACL));

	if (!InitializeAcl(pEmptyDacl, sizeof(ACL), ACL_REVISION))
	{
		dwErr = GetLastError();
	}
	else
	{
		dwErr = SetSecurityInfo(hProcess, SE_KERNEL_OBJECT,
			DACL_SECURITY_INFORMATION, NULL, NULL, pEmptyDacl, NULL);
	}

	free(pEmptyDacl);
	return dwErr;
}

DWORD ProtectProcess(void)
{
	HANDLE hProcess = GetCurrentProcess();
	PACL pEmptyDacl;
	DWORD dwErr;

	// using malloc guarantees proper alignment
	pEmptyDacl = (PACL)malloc(sizeof(ACL));

	if (!InitializeAcl(pEmptyDacl, sizeof(ACL), ACL_REVISION))
	{
		dwErr = GetLastError();
	}
	else
	{
		dwErr = SetSecurityInfo(hProcess, SE_KERNEL_OBJECT,
			DACL_SECURITY_INFORMATION, NULL, NULL, pEmptyDacl, NULL);
	}

	free(pEmptyDacl);
	return dwErr;
}

static const char consoleNameAlphanum[] = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int consoleNameLength = sizeof(consoleNameAlphanum) - 1;
char genRandomConsoleName()
{
	return consoleNameAlphanum[rand() % consoleNameLength];
}

int Overlay::WinMain(HINSTANCE hInstance, HINSTANCE hSecInstance, LPSTR nCmdLine, INT nCmdShow)
{
	ProtectProcess();
	ProtectThread();

	std::string Consolenamestr;

	for (unsigned int i = 0; i < 20; ++i)
	{
		Consolenamestr += genRandomConsoleName();
	}

	hInstance = 0;
	WNDCLASSEX wClass;
	wClass.cbClsExtra = NULL;
	wClass.cbSize = sizeof(WNDCLASSEX);
	wClass.cbWndExtra = NULL;
	wClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
	wClass.hCursor = LoadCursor(0, IDC_ARROW);
	wClass.hIcon = LoadIcon(0, IDI_APPLICATION);
	wClass.hIconSm = LoadIcon(0, IDI_APPLICATION);
	wClass.hInstance = hInstance;
	wClass.lpfnWndProc = WindowProc;
	wClass.lpszClassName = Consolenamestr.c_str();
	wClass.lpszMenuName = Consolenamestr.c_str();
	wClass.style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClassEx(&wClass))
	{
		assert(RegisterClassEx);
		exit(1);
	}
	
	if (g_hWindow)
	{ 
		targetWindow = g_hWindow;
		GetWindowRect(targetWindow, &tSize);
		overlaySize[0] = tSize.right - tSize.left;
		overlaySize[1] = tSize.bottom - tSize.top;
	
		
		overlayWindow = CreateWindowExA(WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED, Consolenamestr.c_str(), Consolenamestr.c_str(), WS_POPUP, 1, 1, overlaySize[0], overlaySize[1], 0, 0, 0, 0);
		SetLayeredWindowAttributes(overlayWindow, 0, 1.0f, LWA_ALPHA);
		SetLayeredWindowAttributes(overlayWindow, 0, RGB(0, 0, 0), LWA_COLORKEY);

		DwmExtendFrameIntoClientArea(overlayWindow, &windowMargin);

		 
		SetForegroundWindow(targetWindow);
	} 

	D3D9XInit(overlayWindow);
	 
	CreateThread(nullptr, SIZE_T(), FocusOnWindow, hInstance, DWORD(), nullptr);
 
	ShowWindow(overlayWindow, SW_SHOW); 

	ITaskbarList *pTaskList = NULL;
	HRESULT initRet = CoInitialize(NULL);
	HRESULT createRet = CoCreateInstance(CLSID_TaskbarList,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_ITaskbarList,
		(LPVOID*)&pTaskList);

	if (createRet == S_OK)
	{
		pTaskList->DeleteTab(overlayWindow);

		pTaskList->Release();
	}

	CoUninitialize();

	for (;;)
	{
		if (PeekMessage(&windowMessage, overlayWindow, UINT32(), UINT32(), PM_REMOVE))
		{
			DispatchMessage(&windowMessage);
			TranslateMessage(&windowMessage);
		}
	}
	return 0;
}

DWORD WINAPI Overlay::FocusOnWindow(LPVOID hModule)
{
	for(;;)
	{ 
		if (g_hWindow)
		{  
			
			overlaySize[0] = GetWindowSize(g_hWindow).x;
			overlaySize[1] = GetWindowSize(g_hWindow).y;

			DWORD dwStyle = GetWindowLong(g_hWindow, GWL_STYLE);
			if (dwStyle & WS_BORDER)
			{ 
				MoveWindow(overlayWindow, GetWindowPosition(g_hWindow).x, GetWindowPosition(g_hWindow).y, overlaySize[0], overlaySize[1], true);
			}
			else
			MoveWindow(overlayWindow, GetWindowPosition(g_hWindow).x, GetWindowPosition(g_hWindow).y, overlaySize[0], overlaySize[1], true);
		}
		else
		{
			assert(g_hWindow);
		}
	}

	return EXIT_SUCCESS;
}
Overlay* Overlay::GetInstance()
{
	if (!m_pInstance)
		m_pInstance = new Overlay();

	return m_pInstance;
}