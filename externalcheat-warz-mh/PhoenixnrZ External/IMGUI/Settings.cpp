#include "stdafx.h"

//- Function-CheckBox
CBoolCvar CvarPlayerName("PlayerName");
CBoolCvar CvarPlayerDistance("PlayerDist");
CBoolCvar CvarPlayerHealth("PlayerName");
CBoolCvar CvarPlayerWeapon("PlayerWeapon");
CBoolCvar CvarPlayerBox("PlayerBox");
CIntCvar  CvarPlayerBoxType("PlayerBoxType");
CBoolCvar CvarPlayerTracers("PlayerTracer");
CBoolCvar CvarPlayerSkeleton("PlayerSkeleton");
CBoolCvar CvarBackpack("CvarBackpack");
CBoolCvar AirSwim("AirSwim");
CBoolCvar Disconnect("Disconnect");
CIntCvar CvarPlayerEspDistance("PlayerMaxDist");
CBoolCvar CvarPlayerRank("PlayerRank");
CIntCvar pFov("pFov");

CBoolCvar CvarZombieName("ZombieName");
CBoolCvar CvarZombieDistance("ZombieDist");
CBoolCvar CvarZombieHealth("ZombieHealth");
CBoolCvar CvarZombieBox("ZombieBox");
CIntCvar  CvarZombieBoxType("ZombieBoxType");
CBoolCvar CvarZombieTracers("ZombieTracer");
CBoolCvar CvarZombieSkeleton("ZombieSkeleton");
CIntCvar CvarZombieEspDistance("ZombieMaxDist");

CBoolCvar CvarItemName("ItemName");
CBoolCvar CvarItemNameLegible("ItemNameLegible");

CBoolCvar CvarAmountofAmmo("AmountofAmmo");

CBoolCvar CvarItemAmmo("ItemAmmo");
CBoolCvar CvarItemGuns("ItemGuns");
CBoolCvar CvarItemGrenades("ItemGrenades");
CBoolCvar CvarItemConsumable("ItemConsumeable");
CBoolCvar  CvarItemMelee("ItemMelee");
CBoolCvar CvarItemFood("ItemFood");
CBoolCvar CvarItemWater("ItemWater");
CBoolCvar SNP("Sni");
CBoolCvar CvarItemWear("ItemWear");
CIntCvar CvarItemEspDistance("ItemMaxDist");
CBoolCvar CvarItemBox("ItemBox");
CIntCvar CvarItemBoxType("ItemBoxType");

CIntCvar CvarRed("GlobalSliderColorR");
CIntCvar CvarGreen("GlobalSliderColorG");
CIntCvar CvarBlue("GlobalSliderColorB");
CIntCvar CvarEnemiesRed("EnemiesR");
CIntCvar CvarEnemiesGreen("EnemiesG");
CIntCvar CvarEnemiesBlue("EnemiesB");
CIntCvar CvarAlliesRed("AlliesR");
CIntCvar CvarAlliesGreen("AlliesG");
CIntCvar CvarAlliesBlue("AlliesB");
CIntCvar CvarHiddenRed("HiddenR");
CIntCvar CvarHiddenGreen("HiddenG");
CIntCvar CvarHiddenBlue("HiddenB");

// RADAR
CBoolCvar CvarRadar("RadarEnable");
CBoolCvar CVarRadarBG("RadarBackground");
CBoolCvar CVarRadarOutline("RadarOutline");
CBoolCvar CVarRadarCross("RadarCross");
CBoolCvar CVarRadarClip("RadarClipToFrame");
CIntCvar CvarRadarX("PositionX");
CIntCvar CvarRadarY("PositionY");
CIntCvar CvarRadarSize("Size");
CIntCvar CvarRadarZoom("Zoom");
CIntCvar CvarRadarPingSize("PingSize");
CIntCvar CvarBGOpacity("BackgroundOpacity");
CIntCvar CvarDivOpacity("DividerOpacity");
CBoolCvar CvarRadarFriendly("RadarFriendly");

// Stats
CBoolCvar CvarNPI("NearstWidget");
CBoolCvar CvarStats("StatWidget");
CIntCvar CvarStatsX("StatY");
CIntCvar CvarStatsY("StatX");
CIntCvar CvarNPIX("NearstY");
CIntCvar CvarNPIY("NearstX");

// AUTO AIM
CBoolCvar CvarAimbot("EnableAimbot");
CBoolCvar CvarAimbot1("EnableAimbot");
CBoolCvar CvarAimbot3("EnableAimbot");
CBoolCvar CvarAimbot2("EnableAimbot");
//CBoolCvar CvarplayBox1("EnableAimbot");
CBoolCvar CvarAutoAim("AutoAim");
CIntCvar CvarAimKey("AimHotKey");
CIntCvar CvarAimBone("AimBone");
CIntCvar CvarAimStyle("TargetStyle");
CBoolCvar CvarAimCheckVis("AimCheckVis");
CBoolCvar CvarAimFriendly("AimFriendly");
CBoolCvar CvarMagicBullets("MagicBullets");
CBoolCvar CvarInstantKill("InstantKill");
CBoolCvar CvarNoRecoil("NoRecoil");
CBoolCvar CvarNoSpread("NoSpread");
CBoolCvar CvarBulletDrop("BulletDrop");
CBoolCvar CvarKnifeAim("KnifeBot");
CBoolCvar CvarAutoShoot("AutoShoot");
CBoolCvar CvarAutoPredict("AutoPredict");
CBoolCvar CvarLimitFOV("LimitFOV");
CBoolCvar CvarZombieAim("ZombieAiming");
CFloatCvar CvarLimitFOVScale("LimitFOVScale");
CBoolCvar CvarSilentAim("SiletAim");
CIntCvar CvarShootDelay("ShootDelay");

// VISUALS
CBoolCvar CvarDrawFps("DrawFPS");
CBoolCvar CvarDrawTime("DrawTime");
CBoolCvar CvarCrosshair("HudCrosshair");
CBoolCvar CvarShowAimBone("ShowAimBone");
CBoolCvar CvarDayTime("ForceDayTime");

// MISC
CBoolCvar CvarDisableBreathing("DisableBreathing");
CBoolCvar CvarDrawStats("DrawStats");
CBoolCvar CvarNoBlood("NoBloodOverlay");
CBoolCvar CvarStamina("UnlimitedStamina");
CBoolCvar CvarNoBulletDrop("NoBulletDrop");
CBoolCvar CvarNoSway("NoSway");
CBoolCvar CvarRapidfire("Rapidfire");
CBoolCvar CvarSuperJump("SuperJump");
CBoolCvar CvarSafeZoneUnlock("SafeZoneShooting");
CBoolCvar CvarWalkThroughWalls("WalkThroughWalls");
CBoolCvar CvarInstantPickup("InstantPickup");
CBoolCvar CvarEnemyShield("EnemyShield");
CBoolCvar CvarEnemyShieldPlayer("AttackPlayer");
CBoolCvar CvarEnemyShieldZombie("AttackZombie");
CBoolCvar CvarNoFalldamage("NoFallDmg");
CBoolCvar CvarNoZombieDetection("NoZombieDetection");
CBoolCvar CvarGhostMode("Ghosting");
CIntCvar CvarGhostKey("GhostKey");
CBoolCvar CvarNoClip("NoClip");
CBoolCvar CvarplayerXYZ("player");
CBoolCvar CvarAutoDC("AutoDC");
CBoolCvar CvardrawRect("drawRect");
CIntCvar CvarNoClipKey("NoClipKey");
CFloatCvar CvarNoClipSpeed("NoClipSpeed");
CBoolCvar CvarInstantDisconnect("InstantDisconnect");
CIntCvar CvarInstantDisconnectKey("InstantDisconnectKey");
CBoolCvar CvarNightVision("Nightvision");
CBoolCvar Pickup("Pickup");

CBoolCvar CvarWeaponVelocity("WeaponVelocity");
CBoolCvar CvarUnlimitedSprint("UnlimitedSprint");
CBoolCvar CvarIntantHit("Intant Hit");

/* slider color selection */
CIntCvar CvarPlayerRed("PlayerRed");
CIntCvar CvarPlayerGreen("PlayerGreen");
CIntCvar CvarPlayerBlue("PlayerBlue");

CIntCvar CvarZombieRed("ZombieRed");
CIntCvar CvarZombieGreen("ZombieBlue");
CIntCvar CvarZombieBlue("ZombieGreen");

CIntCvar CvarItemRed("ItemRed");
CIntCvar CvarItemGreen("ItemGreen");
CIntCvar CvarItemBlue("ItemBlue");
//- Function-DropDown
CIntCvar  TypeHack1("DropDown");
CIntCvar  TypeHack2("DropDown");

CBoolCvar WeaponHack("WeaponHack");
CBoolCvar Superjump("Superjump");
CBoolCvar SafeZone("SafeZone");


Setting setting;

