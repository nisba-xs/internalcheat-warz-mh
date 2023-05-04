class CBoolCvar
{
public:
CBoolCvar(PCHAR cCvarName) 
{
cName = cCvarName; 
}
BOOL SaveCvar(LPCTSTR lpAppName, LPCTSTR lpFileName);
BOOL LoadCvar(LPCTSTR lpAppName, BOOL bDefaultValue, LPCTSTR lpFileName);
LPCSTR cName;
BOOL bValue;
};

class CIntCvar
{
public:
CIntCvar(PCHAR cCvarName)
{ 
cName = cCvarName; 
}
BOOL SaveCvar(LPCTSTR lpAppName, LPCTSTR lpFileName);
INT LoadCvar(LPCTSTR lpAppName, INT iDefaultValue, LPCTSTR lpFileName);
LPCSTR cName;
INT iValue;
};

class CFloatCvar
{
public:
CFloatCvar(PCHAR cCvarName)
{ 
cName = cCvarName; 
}
BOOL SaveCvar(LPCTSTR lpAppName, LPCTSTR lpFileName);
BOOL LoadCvar(LPCTSTR lpAppName, FLOAT fDefaultValue, LPCTSTR lpFileName);
LPCSTR cName;
FLOAT fValue;
};


class Setting {
public : 


};

extern Setting setting;

//- Function-CheckBox
extern CBoolCvar CvarPlayerName;
extern CBoolCvar CvarPlayerDistance;
extern CBoolCvar CvarPlayerHealth;
extern CBoolCvar CvarPlayerWeapon;
extern CBoolCvar CvarPlayerBox;
extern CIntCvar  CvarPlayerBoxType;
extern CBoolCvar CvarPlayerTracers;
extern CBoolCvar CvarPlayerSkeleton;
extern CBoolCvar CvarBackpack;

extern CBoolCvar CvarPlayerRank;
extern CIntCvar CvarPlayerEspDistance;
extern CIntCvar pFov;
extern CBoolCvar CvarZombieName;
extern CBoolCvar CvarZombieDistance;
extern CBoolCvar CvarZombieBox;
extern CIntCvar  CvarZombieBoxType;
extern CBoolCvar CvarZombieTracers;
extern CBoolCvar CvarZombieSkeleton;
extern CIntCvar CvarZombieEspDistance;

extern CBoolCvar CvarItemName;
extern CBoolCvar CvarItemNameLegible;
extern CBoolCvar CvarAmountofAmmo;
extern CBoolCvar CvarItemBox;
extern CIntCvar CvarItemBoxType;
extern CBoolCvar CvarItemAmmo;
extern CBoolCvar CvarItemGuns;
extern CBoolCvar CvarItemGrenades;
extern CBoolCvar CvarItemConsumable;
extern CBoolCvar  CvarItemMelee;
extern CBoolCvar CvarItemFood;
extern CBoolCvar CvarItemWater;
extern CBoolCvar SNP;
extern CBoolCvar CvarItemWear;
extern CIntCvar CvarItemEspDistance;

// RADAR
extern CBoolCvar CvarRadar;
extern CBoolCvar CVarRadarBG;
extern CBoolCvar CVarRadarOutline;
extern CBoolCvar CVarRadarCross;
extern CBoolCvar CVarRadarClip;
extern CIntCvar CvarRadarX;
extern CIntCvar CvarRadarY;
extern CIntCvar CvarRadarSize;
extern CIntCvar CvarRadarZoom;
extern CIntCvar CvarRadarPingSize;
extern CIntCvar CvarBGOpacity;
extern CIntCvar CvarDivOpacity;
extern CBoolCvar CvarRadarFriendly;

// Stats & NPI
extern CBoolCvar CvarNPI;
extern CBoolCvar CvarStats;
extern CIntCvar CvarStatsX;
extern CIntCvar CvarStatsY;
extern CIntCvar CvarNPIX;
extern CIntCvar CvarNPIY;

// Aimbot
extern CBoolCvar CvarAimbot;
extern CBoolCvar CvarAimbot1;
extern CBoolCvar CvarAimbot3;
extern CBoolCvar CvarAimbot2;
//extern CBoolCvar CvarplayBox1;
extern CBoolCvar CvarAutoAim;
extern CIntCvar CvarAimKey;
extern CIntCvar CvarAimBone;
extern CIntCvar CvarAimStyle;
extern CBoolCvar CvarAimCheckVis;
extern CBoolCvar CvarAimFriendly;
extern CBoolCvar CvarMagicBullets;
extern CBoolCvar CvarInstantKill;
extern CBoolCvar CvarNoRecoil;
extern CBoolCvar CvarNoSpread;
extern CBoolCvar CvarBulletDrop;
extern CBoolCvar CvarKnifeAim;
extern CBoolCvar CvarAutoShoot;
extern CBoolCvar CvarAutoPredict;
extern CBoolCvar CvarLimitFOV;
extern CBoolCvar CvarZombieAim;
extern CFloatCvar CvarLimitFOVScale;
extern CBoolCvar CvarSilentAim;
extern CIntCvar CvarShootDelay;

// VISUALS
extern CBoolCvar CvarShowAmmo;
extern CBoolCvar CvarShowAimBone;
extern CBoolCvar CvarCrosshair;
extern CBoolCvar CvarDayTime;

// MISC
extern CBoolCvar CvarDrawFps;
extern CBoolCvar CvarDrawTime;
extern CBoolCvar CvarDisableBreathing;
extern CBoolCvar CvarDrawStats;
extern CBoolCvar CvarNoBlood;
extern CBoolCvar CvarShowClock;
extern CBoolCvar CvarStamina;
extern CBoolCvar CvarNoBulletDrop;
extern CBoolCvar CvarNoSway;
extern CBoolCvar CvarRapidfire;
extern CBoolCvar CvarSuperJump;
extern CBoolCvar CvarSafeZoneUnlock;
extern CBoolCvar CvarWalkThroughWalls;
extern CBoolCvar CvarInstantPickup;
extern CBoolCvar CvarEnemyShield;
extern CBoolCvar CvarEnemyShieldPlayer;
extern CBoolCvar CvarEnemyShieldZombie;
extern CBoolCvar CvarNoFalldamage;
extern CBoolCvar CvarNoZombieDetection;
extern CBoolCvar CvarGhostMode;
extern CIntCvar CvarGhostKey;
extern CBoolCvar CvarNoClip;
extern CBoolCvar CvarplayerXYZ;
extern CBoolCvar WeaponHack;
extern CBoolCvar Superjump;
extern CBoolCvar SafeZone;
extern CBoolCvar CvarAutoDC;
extern CIntCvar CvarNoClipKey;
extern CFloatCvar CvarNoClipSpeed;
extern CBoolCvar CvarInstantDisconnect;
extern CIntCvar CvarInstantDisconnectKey;
extern CBoolCvar CvarNightVision;
extern CBoolCvar Pickup;
extern CBoolCvar CvarUnlimitedSprint;
extern CBoolCvar CvarIntantHit;
extern CBoolCvar  CvarWeaponVelocity;

//- Function-DropDown
extern CIntCvar  TypeHack1;
extern CIntCvar  TypeHack2;




