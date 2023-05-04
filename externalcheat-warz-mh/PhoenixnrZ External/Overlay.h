
#pragma once
#include "define.h"

class Overlay
{
public:
	static Overlay* GetInstance();

	static char * targetWindowName;
	static HWND targetWindow;
	static HWND overlayWindow;
	static MARGINS windowMargin;
	static float overlaySize[2];


	// DX9 
	static IDirect3DDevice9Ex* pDevice;
	static ID3DXFont* pFont;
	static IDirect3D9Ex* pObject;
	static ID3DXLine* pLine;
	static D3DPRESENT_PARAMETERS pParams;

	static long _stdcall WindowProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
	static DWORD WINAPI FocusOnWindow(LPVOID hModule);
	static DWORD D3D9XInit(HWND hWnd);
	static int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hSecInstance, LPSTR nCmdLine, INT nCmdShow);
private:
	Overlay();
	~Overlay();



	static Overlay* m_pInstance;
};
#pragma once
