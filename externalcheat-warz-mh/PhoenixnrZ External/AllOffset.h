#pragma once


#define OBJTYPE_HUMAN 0x20
#define OBJTYPE_HUMAN1 0x21
#define OBJTYPE_ZOMBIE1 0x20001

#define OBJTYPE_DroppedItem 0x240005

#define VALID( x ) ( x != NULL && HIWORD( x ) )






#define pGame_Adr                            0xD00EA0 - 0x400000      //  clientgame - g_pClientLo   Sounds/MainMenuGUI/UI_MENU_MUSIC    AObject บน
#define pGame_Xor                            0x12445434            //  0x28F51F6A    0xAB20A04D  0x1735146A  0x7329531B   ChatTemporarilyBanned

#define pGameWorld_Adr                       0xD00F08 - 0x400000      //	gameworld  -  destroyed_light_obj_color   obj_DroppedItem
#define pGameWorld_Xor                       0x82445434          //  0xFC5AD98D 0xAB20A10D   0x00000000	 -  F3 AB F3 0F 11 86 ?? ?? 00 00    บน


#define dwRenderAddress                       0x125C874 - 0x400000                    // r3dRender.h

#define matTmp_off			                   0x220		                           // PS_DS_SSR_VS DS_SSR_vs.hls
#define matView_off			                   0x1A0		                           // PS_DS_SSR_VS


//#define pGame_Adrss                           0x53B8D0 - 0x400000                     // updateClientSurvivorWeight
//
//#define pGameWorld_Adrss                         0x55DA10 - 0x400000                     // obj_Lake

#define GetLocalPlayer_off                     0xD1B3C                        // pl_%u
#define GetLocalPlayer_xor                     0x8F70AB49                      // pl_%u

#define XOR_OBJLIST_MAX	                       0x13E1855C                            // !bInited
#define XOR_OBJLIST_PTR                        0x304CFD16								 // !bInited


//#define PHYSICS_Adr                          0x13DD504 - 0x400000  // ASSERT at file %s, line %d: g_pPhysicsWorld  VehicleMan     PhysXSDK\n 


//////////////////////////////////////////////////////////////////////////////////////////

//ค่าหลัก
//////////////////////////////////////////////////////////////////////////////////////////




#define m_pSkeleton_off			               0x1228	                           // PrimaryWeaponBone
#define BoneCoeff_off			               0x1464		                           // PrimaryWeaponBone
#define CSkeleton_off			               0x28                                    // Bip01_Head

#define FastPickupIteam_off				       0x1278                     // obj_Gravestone
#define PlayerGetYaw  				           0x13E4								   // player%02d
#define SuperJump_off                          0x1358                // PLAYER_JUMPING_F   

#define PlayerDrink                            0x12F8                       // PLAYER_DRINK
#define PlayerbDead                            0x17B0                            // $FR_PLAY_GAME_SURVIVOR_DEAD

#define PlayerHeal                             0x3DC               // PLAYER_EAT
#define PlayerEat                              0x3D0                 // PLAYER_EAT
#define RespawnPlayer                          0x132C                  // Hit_Death

#define Norecoil1                              0x181C						   // wpn
#define Norecoil2                              0x181C                           // wpn
#define Norecoil3                              0x181C                // wpn
#define Norecoil4                              0x181C                 // wpn
#define Nospread                               0x38C                   // showSlots movss ค่า show

#define NameLenAddress                         0x430					           // ReceivedTradeRequestFromPlr
#define NameAddress							   0x3F0                         // ReceivedTradeRequestFromPlr



//////#define FEESEZ                               0x438                   //  81 C6 ? ? ? ? 42   Killed by - 56 8B B3 ?? ?? 00 00 8D 83 ?? ?? 00 00
//////#define namesub                              0x77                    //  หา sub หรือ add
//////#define NoName                               0                       //  [0 +] [1 -]    ถ้ามันเป็น add ให้ใส่ 0        ถ้าเป็น sub ให้ใส่ 1 







//////////////////////////////////////////////////////////////////////////////////////////
#define TeamId                                 0x41C                      // team subบน
#define ClanId                                 0x464                            // clan  s
#define Clan_off                               0x46C                    // CLAN   lea sub บน

#define GetHealth_off			               0x4DC                           // Health
#define Objecttype_off                         0x210                                // Weapon owner must be obj_Player            isObjType(OBJTYPE_H   
#define Getposition_off                        0x24                           // F3 0F 7E 07 66 0F D6 86 ?? ?? ?? ?? 8B 47 08
//////////////////////////////////////////////////////////////////////////////////////////




//
//////////////////////////////////////////////////////////////////////////////////////////
// 
//เกรียน
//////////////////////////////////////////////////////////////////////////////////////////
#define AirSwim_Offset                       0x1378              //  ASSERT AT FILE %S, LINE %D: WPN\N     -   isUsableItem  8B 87 ?? ?? 00 00 8B B4 87 ?? ?? 00 00
#define GetWeapon_Offset                     0x1240             // ล่าง
#define WEAPON_XOR                           0xFC9A43A5            //  0xFC9A43A5  0xB2A5CA13  0x00770000  0x07707527
#define มาโคร                                0x2EC              //  wi.q  -  flashl  - bone_a
#define สุ่มกระสุน                              0x2EC              //  wi.q  -  flashl  - bone_a
#define ยิงรัว                                 0x2E0             //  wi.q  -  flashl  - bone_a
#define รีโหลดไว                              0x30               //  _Reload
//////////#define ดูดหัว                                0x0

