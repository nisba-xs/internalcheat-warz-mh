#include <detours.h>
#pragma once
obj_Player* localPlayer = NULL;





static ObjectManager* GameWorld()
{
	ObjectManager* pGamePlus = (ObjectManager*)(*(DWORD*)((DWORD)hGameBase + pGameWorld_Adr));

	pGamePlus = (ObjectManager*)((DWORD)pGamePlus ^ pGameWorld_Xor);

	return pGamePlus; //pGame_Adr
}

static ClientGameLogic* pGetGame()
{
	ClientGameLogic* pGamePlus = (ClientGameLogic*)(*(DWORD*)((DWORD)hGameBase + pGame_Adr));

	pGamePlus = (ClientGameLogic*)((DWORD)pGamePlus ^ pGame_Xor);

	return pGamePlus; //pGameWorld_Adr
}


static tRender* Render1()
{
	return (tRender*)(*(DWORD*)((DWORD)hGameBase + dwRenderAddress));
}

void Engine()
{
	GetRender = (tRender)((DWORD)Render1);
	pRenderer = GetRender();

	while (pGame == 0)
	{
		GetGame = (tGetGame)((DWORD)pGetGame);
		pGame = GetGame();
		//_cprintf("pGame %p\n",pGame);
	}

	while (pGameWorld == 0)
	{
		GetGameWorld = (tGetGameWorld)((DWORD)GameWorld);
		pGameWorld = GetGameWorld();
		//_cprintf("pGameWorld %p\n",pGameWorld);
	}
	//system("cls");


}


//////////////สำหรับใช้แบบsub

//////#pragma once

//obj_Player* localPlayer = NULL;

//ObjectManager* GetGameWorldPtr()
//{
//	DWORD dwFunc = (DWORD)hGameBase + pGameWorld_Adrss;
//	if (dwFunc != 0)
//	{
//		__asm
//		{
//			call dwFunc
//		}
//	}
//}
//
//static tRender* Render1()
//{
//	return (tRender*)(*(DWORD*)((DWORD)hGameBase + dwRenderAddress));
//}
//
//void Engine()
//{
//	GetRender = (tRender)((DWORD)Render1);
//	pRenderer = GetRender();
//
//	DWORD pGetGame = 0;
//
//	pGetGame = (DWORD)hGameBase + pGame_Adrss;
//
//	while (pGame == 0)
//	{
//		GetGame = (tGetGame)((DWORD)pGetGame);
//		pGame = GetGame();
//	}
//
//	while (pGameWorld == 0)
//	{
//		pGameWorld = GetGameWorldPtr();
//	}
//}
