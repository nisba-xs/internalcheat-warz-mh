class r3dRenderLayer* pRenderer = NULL;
class ClientGameLogic* pGame = NULL;
class ObjectManager* pGameWorld = NULL;

#include "AllOffset.h"
#include "Class.h"
#include "Call.h"
#include "DirectK.h"




int Skeleton;
int Aimbot;
int Aimbotx2;

void BeginScene(int a);
void DrawScene();
void EndScene(int A);

LPD3DXFONT pFont;

void DrawRect(IDirect3DDevice9* m_pD3Ddev, float x, float y, float w, float h, D3DCOLOR Color)
{
	struct Vertex
	{
		float x, y, z, ht;
		DWORD Color;
	};
	Vertex qV[4] = {
		{ (float)x, (float)(y + h), 0.0f, 1.0f, Color },
		{ (float)x, (float)y, 0.0f, 1.0f, Color },
		{ (float)(x + w), (float)(y + h), 0.0f, 1.0f, Color },
		{ (float)(x + w), (float)y, 0.0f, 1.0f, Color }
	};
	const DWORD D3DFVF_TL = D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1;
	m_pD3Ddev->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	m_pD3Ddev->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	m_pD3Ddev->SetFVF(D3DFVF_TL);
	m_pD3Ddev->SetTexture(0, NULL);
	m_pD3Ddev->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, qV, sizeof(Vertex));
}

bool m_bIsInitalized = false;

void PrintText(int x, int y, DWORD color, const char* fmt, ...)
{
	char draw[99] = "";
	va_list va_alist;
	va_start(va_alist, fmt);
	RECT Rectangle = { x, y, 1000 + x, 1000 + y };
	_vsnprintf_s(draw + strlen(draw), 512, 511, fmt, va_alist);
	va_end(va_alist);
	// menu->drawText(x,y, r,g,b,    draw);
	pFont->DrawText(NULL, draw, -1, &Rectangle, 0, color);
}

bool ComparePattern(DWORD address, DWORD patternAddress, char* mask) {
	int patternLen = strlen(mask);

	for (auto i = 1; i < patternLen; i++) {
		if (mask[i] != *"?" && *(char*)(address + i) != *(char*)(patternAddress + i)) {  // Compare each byte of the pattern with each byte after the current scanning address
			return false;
		}
	}
	if (address != patternAddress) {  // Make sure we aren't returning a match for the pattern defined within your DLLMain
		return true;
	}
	return false;
}

DWORD FindPattern(DWORD patternAddress, char* mask) {
	SYSTEM_INFO sysInfo; // Holds System Information
	GetSystemInfo(&sysInfo);
	DWORD procMin = (DWORD)sysInfo.lpMinimumApplicationAddress;  // Minimum memory address of process
	DWORD procMax = (DWORD)sysInfo.lpMaximumApplicationAddress;  // Maximum memory address of process

	MEMORY_BASIC_INFORMATION mBI, mBINext;

	DWORD firstOldProtect = NULL;
	DWORD secondOldProtect = NULL;

	DWORD patternSize = (DWORD)strlen(mask);

	std::vector<DWORD> matches;  // Holds all pattern matches

	while (procMin < procMax) {  // While still scanning memory

		VirtualQueryEx(GetCurrentProcess(), (LPVOID)procMin, &mBI, sizeof(MEMORY_BASIC_INFORMATION));  // Get memory page details

		if ((mBI.State == MEM_COMMIT) && (mBI.Type == MEM_PRIVATE)) {  // Check state of current page

			VirtualProtect((LPVOID)procMin, mBI.RegionSize, PAGE_EXECUTE_READWRITE, &firstOldProtect);  // Set page to read/write/execute

			for (auto n = (DWORD)mBI.BaseAddress; n < (DWORD)mBI.BaseAddress + mBI.RegionSize; n += 0x01) {  // For each byte in this page

				if (n + patternSize > procMax) {  // If our pattern will extend past the maximum memory address, break
					break;
				}

				if (*(char*)n == (*(char*)patternAddress)) {  // If first byte of pattern matches current byte

					if (n + patternSize < (UINT)mBI.BaseAddress + mBI.RegionSize) {  // If entire length of pattern is within this page

						if (ComparePattern((DWORD)n, patternAddress, mask)) {  // Test if full pattern matches
							matches.push_back((DWORD)n);  // If it does, add it to the vector
						}
					}
					else {  // If it isn't within the same page
						VirtualQueryEx(GetCurrentProcess(), (LPVOID)(procMin + mBI.RegionSize), &mBINext, sizeof(MEMORY_BASIC_INFORMATION));  // Same memory page stuff with next page

						if ((mBINext.State == MEM_COMMIT) && (mBINext.Type == MEM_PRIVATE)) {
							VirtualProtect((LPVOID)(procMin + mBI.RegionSize), mBINext.RegionSize, PAGE_EXECUTE_READWRITE, &secondOldProtect);

							if (ComparePattern((DWORD)n, patternAddress, mask)) {
								matches.push_back((DWORD)n);

							}
						}

					}

				}
			}


			VirtualProtect((LPVOID)procMin, mBI.RegionSize, firstOldProtect, NULL);  // Reset memory page state of first page

			if (secondOldProtect) {  // If we scanned into the second page
				VirtualProtect((LPVOID)procMin, mBINext.RegionSize, secondOldProtect, NULL);  // Reset memory page state of second page
				secondOldProtect = NULL;
			}
		}
		procMin += mBI.RegionSize;  // Start scanning next page
	}


	if (!matches.empty()) {
		return matches[0];  // If we had some matches, return the first. -- Change this and return type of functon if you need full list of matches
	}
	else {
		return NULL;  // Return NULL if no matches
	}
}

#include "Menu.h"

void PickupDraw()
{
	if (!m_bIsInitalized)
	{
		Engine();
		D3DXCreateFontA(Overlay::GetInstance()->pDevice, 14, 0, FW_NORMAL, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &pFont);
		m_bIsInitalized = true;
	}
	Overlay::GetInstance()->pDevice->Clear(0, 0, D3DCLEAR_TARGET, 0, 1.0f, 0);
	Overlay::GetInstance()->pDevice->BeginScene();

	if (GetForegroundWindow() == Overlay::GetInstance()->targetWindow)
	{
		__try
		{
			BeginScene(NULL);
			DrawScene();
			EndScene(NULL);
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
			ResumeThread(GetCurrentThread());
		}
	}

	Overlay::GetInstance()->pDevice->EndScene();
	Overlay::GetInstance()->pDevice->Present(0, 0, 0, 0);
}

D3DXVECTOR3 pGetBonePos(obj_Player* pPlayer, DWORD i, D3DXVECTOR3* Pos)
{
	if (!pPlayer || !pPlayer->m_Skeleton())
		return D3DXVECTOR3(0, 0, 0);

	if (!pPlayer->m_Skeleton()->BonePtr)
		return D3DXVECTOR3(0, 0, 0);

	D3DXMATRIX v6, v7, BoneMatrix;

	D3DXMatrixRotationYawPitchRoll(&v6, 0.0, 1.570796251296997, 0.0);
	BoneMatrix = pPlayer->m_Skeleton()->BonePtr->pBones[i].BoneMatrix;
	D3DXMatrixMultiply(&BoneMatrix, &BoneMatrix, &pPlayer->m_BoneCoeff());
	D3DXMatrixMultiply(&v7, &v6, &BoneMatrix);

	Pos->x = v7._41;
	Pos->y = v7._42;
	Pos->z = v7._43;

	return v7;
}

D3DXVECTOR3 GetBoneOrigin(obj_Player* pPlayer, int iBoneID)
{
	if (!pPlayer != NULL || !pPlayer->m_Skeleton() != NULL)
		return D3DXVECTOR3(0, 0, 0);

	if (!pPlayer->m_Skeleton()->BonePtr != NULL)
		return D3DXVECTOR3(0, 0, 0);

	D3DXMATRIX v6;
	D3DXMATRIX v7;
	D3DXMATRIX BoneMatrix;
	D3DXVECTOR3 Pos;

	D3DXMatrixRotationYawPitchRoll(&v6, 0.0, 1.570796251296997, 0.0);
	BoneMatrix = pPlayer->m_Skeleton()->BonePtr->pBones[iBoneID].BoneMatrix;
	D3DXMatrixMultiply(&BoneMatrix, &BoneMatrix, &pPlayer->m_BoneCoeff());
	D3DXMatrixMultiply(&v7, &v6, &BoneMatrix);

	Pos.x = v7._41;
	Pos.y = v7._42;
	Pos.z = v7._43;

	return Pos;
}

void DrawSkeleton(obj_Player* player, D3DCOLOR dwColour, LPDIRECT3DDEVICE9 pDevice)
{
	int aSkeleton[][2] = {
	{ 1, 2 },{ 2, 3 },{ 3, 4 },{ 4, 5 },{ 5, 6 },
	{ 5, 7 },{ 7, 8 },{ 8, 9 },{ 9, 10 },{ 10, 11 },
	{ 11, 12 },{ 12, 13 },{ 10, 14 },{ 14, 15 },{ 15, 16 },
	{ 10,17 },{ 17,18 },{ 18,19 },{ 10,20 },{ 20,21 },{ 21,22 },
	{ 10,23 },{ 23,24 },{ 24,25 },
	{ 5, 28 },{ 28, 29 },{ 29, 30 },
	{ 30, 31 },{ 31, 32 },{ 31, 35 },{ 35, 36 },
	{ 36, 37 },{ 31, 38 },{ 38, 39 },{ 39, 40 },{ 31, 41 },
	{ 31, 42 },{ 42, 43 },{ 31, 44 },{ 44, 45 },{ 45, 46 },
	{ 53, 54 },{ 54, 55 },{ 55, 56 },
	{ 58, 59 },{ 59, 60 },{ 60, 61 },
	{ 53, 58 },
	};

	for (int i = 0; i < 48; ++i)
	{
		D3DXVECTOR3 Bone1;
		D3DXVECTOR3 Bone2;
		pGetBonePos(player, aSkeleton[i][0], &Bone1);
		pGetBonePos(player, aSkeleton[i][1], &Bone2);
		D3DXVECTOR3 Out1, Out2;

		ProjectToScreen(Bone1, &Out1, pDevice);
		ProjectToScreen(Bone2, &Out2, pDevice);
		DrawLine(pDevice, Out1.x, Out1.y, Out2.x, Out2.y, dwColour);
	}
}

#include "Aim.h"

void BeginScene(int a)
{

}

void LoopHack()
{
	if (Function[0])
	{
		*(float*)((DWORD)localPlayer + Norecoil1) = 0;
		*(float*)((DWORD)localPlayer + Norecoil2) = 0;
		*(float*)((DWORD)localPlayer + Norecoil3) = 0;
		*(float*)((DWORD)localPlayer + Norecoil4) = 0;
	}

	if (Function[1])
	{
		*(float*)((DWORD)localPlayer + Nospread) = 0;
	}

	if (Function[2])
	{
		if (GetAsyncKeyState('G') & 1)
		{
			*(BOOL*)((DWORD)pGame + GetLocalPlayer_off + 0x4) = 0;
		}
	}

	if (Function[3])
	{
		*(float*)((DWORD)localPlayer + FastPickupIteam_off) = 1.2;
	}

	if (Function[4])
	{
		if (GetAsyncKeyState('V'))
		{
			float fNewYaw = localPlayer->GetYAW() - 90;


			float fy = D3DXToRadian(fNewYaw);
			float fc = cos(fy);
			float fs = sin(fy);
			D3DXVECTOR3 move;

			move.z = -(fs * 0.08);
			move.y = +0.0f;
			move.x = -(fc * 0.08);

			D3DXVECTOR3 FinalPos = localPlayer->GetPosition() + move;

			localPlayer->SetPosition(FinalPos);
		}
	}

	if (Function[5])
	{
		*(float*)((DWORD)localPlayer + PlayerHeal) = 0;
		*(float*)((DWORD)localPlayer + PlayerEat) = 0;
	}

	if (Function[6])
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			*(float*)((DWORD)localPlayer + SuperJump_off) = 13; //E234
		}
	}











	









	if (localPlayer->WeaponP() != NULL)
	{
		if (Function[97])
		{
			*(float*)((DWORD)localPlayer->WeaponP() + ÁÒâ¤Ã) = 0;  // ÁÒâ¤Ã
		}
		if (Function[96])
		{
			*(float*)((DWORD)localPlayer->WeaponP() + ÊØèÁ¡ÃÐÊØ¹) = 1;  // ÊØèÁ¡ÃÐÊØ¹
		}
		if (Function[95])
		{
			*(float*)((DWORD)localPlayer->WeaponP() + ÂÔ§ÃÑÇ) = 0;  // ÂÔ§ÃÑÇ
		}
		if (Function[94])
		{
			*(bool*)((DWORD)localPlayer->WeaponP() + ÃÕâËÅ´äÇ) = 1;  // ÃÕâËÅ´äÇ
		}

	}






	if (Function[98])
	{
		if (GetAsyncKeyState('L'))
		{
			*(int*)((DWORD)localPlayer + AirSwim_Offset) = 1; //+3
		}
	}
	int kuy = 30;

	if (Function[7])
	{
		if (GetAsyncKeyState('B'))
		{
			*(float*)((DWORD)localPlayer + RespawnPlayer) = 0.f;
		}
	}

	if (Function[8])
	{
		*(float*)((DWORD)localPlayer + PlayerDrink) = 75;
	}

	if (Function[9])
	{
		if (localPlayer)
		{
			float Health = localPlayer->Gethealth();
			if (Health <= 20)
			{
				*(BOOL*)((DWORD)pGame + GetLocalPlayer_off + 0x4) = 0;
			}
		}
	}
}

void TestObjects()
{
	char txt[99];
	if (pGameWorld && pGameWorld->bInited)
	{
		for (int i = 0; i < pGameWorld->getMaxObjects(); i++)
		{
			GameObject* object = pGameWorld->getObject(i);

			if (object == NULL || object == (GameObject*)localPlayer)
				continue;
			
			D3DXVECTOR3 headVec, screen, box, screenHead, vTargetDistance;
			
			if (object && object->getObjType() == OBJTYPE_HUMAN || object && object->getObjType() == OBJTYPE_HUMAN1)
			{
				obj_Player* player = (obj_Player*)object;

				if (player)
				{
					D3DXVec3Subtract(&vTargetDistance, &player->GetPosition(), &localPlayer->GetPosition());

					float flDistance = D3DXVec3Length(&vTargetDistance);

					float flHealth = player->Gethealth();

					int i = 0;

					pGetBonePos(player, Bip01_Head, &headVec);

					if (ProjectToScreen(player->GetPosition(), &screen, Overlay::GetInstance()->pDevice))
					{
						if (ProjectToScreen(headVec, &screenHead, Overlay::GetInstance()->pDevice))
						{
							box.y = ((screen.y - screenHead.y) > 1.f) ? screen.y - screenHead.y : 1.f;
							box.x = box.y / 2.75f;

							if (Function[10])
							{
								DrawLine(Overlay::GetInstance()->pDevice, screen.x - (box.x / 2), screen.y - box.y, screen.x - (box.x / 2) + box.x, screen.y - box.y, lime);
								DrawLine(Overlay::GetInstance()->pDevice, screen.x - (box.x / 2) + box.x, screen.y - box.y, screen.x - (box.x / 2) + box.x, screen.y - box.y + box.y, lime);
								DrawLine(Overlay::GetInstance()->pDevice, screen.x - (box.x / 2) + box.x, screen.y - box.y + box.y, screen.x - (box.x / 2), screen.y - box.y + box.y, lime);
								DrawLine(Overlay::GetInstance()->pDevice, screen.x - (box.x / 2), screen.y - box.y + box.y, screen.x - (box.x / 2), screen.y - box.y, lime);
							}
						}

						if (Function[11])
						{
							DrawSkeleton(player, white, Overlay::GetInstance()->pDevice);
						}

						

						if (Function[12])
						{
							D3DXVECTOR3 Bone_pos, Bone_Head;

							if (ProjectToScreen(GetBoneOrigin(player, 6) + D3DXVECTOR3(0, 0.110, 0), &Bone_Head, Overlay::GetInstance()->pDevice))
							{
								if (ProjectToScreen(GetBoneOrigin(player, 6) - D3DXVECTOR3(0, 0.02, 0), &Bone_pos, Overlay::GetInstance()->pDevice))
								{
									float BHeight = Bone_Head.y - Bone_pos.y;
									DrawCircle2(Overlay::GetInstance()->pDevice, Bone_Head.x, Bone_Head.y, BHeight, BHeight, white);
								}
							}
						}

						if (Function[13])
						{
							PrintText(screen.x, screen.y + (i * 10), blue, "[%0.1f]", flDistance); ++i;
						}

						if (Function[14])
						{
							float phealth;
							memcpy(&phealth, &flHealth, sizeof(flHealth));
							if (phealth > 100)
								phealth = 100;

							PrintText(screen.x, screen.y + (i * 10), red, "HP : %0.0f", phealth); ++i;
						}


						

					









						if (Function[15])
						{
							if (player->ClanID() != 0)
							{
								D3DCOLOR clanTagColor;
								switch (player->ClanColor())
								{
								default: clanTagColor = D3DCOLOR_XRGB(255, 255, 255, 0);

								case 1: clanTagColor = D3DCOLOR_XRGB(170, 0, 0);
									break;
								case 2: clanTagColor = D3DCOLOR_XRGB(166, 120, 12);
									break;
								case 3: clanTagColor = D3DCOLOR_XRGB(16, 164, 158);
									break;
								case 4: clanTagColor = D3DCOLOR_XRGB(32, 164, 20);
									break;
								case 5: clanTagColor = D3DCOLOR_XRGB(16, 78, 164);
									break;
								case 6: clanTagColor = D3DCOLOR_XRGB(150, 16, 164);
									break;
								case 7: clanTagColor = D3DCOLOR_XRGB(68, 68, 68);
									break;
								case 8: clanTagColor = D3DCOLOR_XRGB(164, 164, 164);
									break;
								}

								PrintText(screen.x, screen.y + (i * 10), clanTagColor, "[%s]", player->CLAN()); ++i;
							}
						}
					}
				}
			}
		}
	}
}

bool MenuRender = 1;
void DrawScene()
{
	D3DDEVICE_CREATION_PARAMETERS d3dcp;
	Overlay::GetInstance()->pDevice->GetCreationParameters(&d3dcp);

	SetWindowDisplayAffinity(d3dcp.hFocusWindow, 0x11);

	//PrintText(10, 20, D3DCOLOR_XRGB(255, 0, 0), "Powered:By SUPERSHOP");
	//PrintText(10, 30, D3DCOLOR_XRGB(255, 0, 0), "Begin : GetPing %i", pGame->getPing());

	RenderMenu(Overlay::GetInstance()->pDevice);

	if (pGame)
	{
		localPlayer = pGame->GetLocalPlayer();

		if (localPlayer)
		{
			LoopHack();
			MatrixToScreen();
			TestObjects();
			AimBone();
		}
	}

	if (Function[33])
	{
		float center_x, center_y;

		HWND hWindow = Overlay::GetInstance()->targetWindow;

		center_x = GetWindowSize(hWindow).x / 2;
		center_y = GetWindowSize(hWindow).y / 2;

		DrawLine(Overlay::GetInstance()->pDevice, center_x - 4, center_y, center_x + 5, center_y, red);
		DrawLine(Overlay::GetInstance()->pDevice, center_x, center_y - 4, center_x, center_y + 5, red);
	}

}

void EndScene(int a)
{

}