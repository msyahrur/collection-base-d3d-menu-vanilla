
#ifndef _CSTRUCT_H
#define _CSTRUCT_H
#define _USE_MATH_DEFINES
#include "xAddy.h"
#include <math.h>
#include <d3dx9math.h>


struct pAimbot
{
	int CH_AimBot;
	int CH_AimDistance;
	int CH_AimKey;
	int CH_AimType;
	int CH_SeeDown;
	int CH_AimEnemy;
	int CH_AimZone;
	int CH_AimBotOnOff;
	int CH_Seefront;
	int NoAimScope;
}cAimbot;


struct User 
{
	int SelectUser;
	int GotoPlayer;
	int KillUser;
	int CH_TELEKILL;
	int Dos;
}cUser;

struct CPlayer
{
 char str1[50244];//0x00
 float NoRecoil1;//0xC444
 float NoRecoil2;//0xC448
 float NoRecoil3;//0xC44C
 char str2[72];//0xC450
 BYTE index;//0xC498
 char str3[19];//0xC499
 float GravityX;//0xC4AC
 float GravityY;//0xC4B0
 float GravityZ;//0xC4B4
 char str4[24];//0xC4B8
 int WeaponState;//0xC4D0
 char str5[15416];//0xC4D4
 float PlayerSpeed;//0x1010C
 float NoSpread;//0x10110
 float FastNadeBlast;//0x10114
 char str6[136];//0x10118
 float PlayerView;//0x101A0
 char str7[4];//0x101A4
 float Pitch;//0x101A8
 char str8[24];//0x101AC
 float Yaw;//0x101C4
 char str9[12];//0x101C8
 float ViewX;//0x101D4
 float ViewY;//0x101D8
 float ViewZ;//0x101DC
 char str10[12];//0x101E0
 WORD Weapon1;//0x101EC
 WORD Weapon2;//0x101EE
 WORD Weapon3;//0x101F0
 char str11[90];//0x101F2
 BYTE PlayerState;//0x1024C
 char str12[155];//0x1024D
 float NoFallDamage;//0x102E8
 char str13[20];//0x102EC
 float PosX;//0x10300
 char str14[4];//0x10304
 float PosY;//0x10310
 char str15[4];//0x10314
 float PosZ;//0x10308
 char str16[100];//0x1030C
 DWORD AutoPlant;//0x10370
 DWORD AutoDefuse;//0x10374
 char str17[14];//0x10378
 DWORD AutoShot;//0x10386
 char str18[110];//0x1038A
 float NOM134IDLE;//0x103F8
};

 
struct CServer
{
CHAR UnknownData1[0xBE8D8];//0x00
DWORD Packet;//0xBE8D8
CHAR UnknownData2[0x378C];//0xBE8DC
INT Master;//0xC2068
CHAR UnknownData3[0x5055];//0xC206C
BYTE Slot1;//0xC70C1
BYTE Slot2;//0xC70C2
BYTE Slot3;//0xC70C3
BYTE Slot4;//0xC70C4
BYTE Slot5;//0xC70C5
BYTE Slot6;//0xC70C6
BYTE Slot7;//0xC70C7
BYTE Slot8;//0xC70C8
CHAR UnknownData4[0x1827B];//0xC70C9
LONG Invisible;//0xDF344
CHAR UnknownData5[0x154C];//0xDF34C
DWORD RoomNumber;//0xE0898
DWORD MyPlayerSlot;//0xE089C
DWORD MyTeam;//0xE08A0- THis comments not acutally or ? - ??
};//OLD ? - ? no.. 

struct CPlayerInfo
{
CHAR UnknownData1[0x6D8];//0x00
CHAR IPAddress[16];//0x6D8
CHAR UnknownData2[0x2DC];//0x6E8
CHAR NAME[16];//0x9C4
CHAR UnknownData3[0x11B4];//0x9D4
INT KILLS;//0x1B88
INT DEATHS;//0x1B8C
INT FLAGS;//0x1B90
INT EXP;
INT HEALTH;//0x1B94
INT MAXHELATH;//0x1B98
CHAR UnknownData4[0x94];//0x1B9C
BYTE ISREDY;//0x1C30
CHAR UnknownData5[0xBB];//0x1C31
BYTE TEAM;//0x1CEC
CHAR UnknownData6[0x4];//0x1B9C
int pClass;//0x1BA0
CHAR UnknownData7[0x1BFB];//0x1CED
};//0x1CF8

struct CServerBase
{
CServer* MyServer;
};

//struct CBase
//{
//CPlayer* pLocal;
//char xJumpToAdress1[1219700];
//CPlayer** pGlobal;
//};


struct CBase
{
CPlayer* pLocal;//0xA53B98
char xJumpToAdress1[0x129C74];//0xA53B9C
CPlayer** pGlobal;//0xB7D810
};

 

struct CLocal
{
	char xJumpToAdress0[32];//0x00
	float PosX;//0x20
    float PosY;//0x24            
    float PosZ;//0x28
    char xJumpToAdress1[36];//0x2C
    float Pitch;//0x50
    float Yaw;//0x54
};

struct CMatrix
{
	D3DXMATRIX Project;//0x00
	D3DXMATRIX View;//0x40
};


CPlayerInfo* GetGlobalInfo( int dwPlayerIndex )
{
	if( dwPlayerIndex > 32 ) return 0;
	return (CPlayerInfo*)(ADR_BASEPOINTER+(OFS_GLOBALSIZE*dwPlayerIndex));
}
INT GetLocalInfo()
{
	DWORD *dwServPtr = (DWORD*)ADR_SERVERPOINTER;
	return *(INT*)((*dwServPtr)+OFS_LOCALSIZE);
}
CLocal* p_Local = NULL;
CBase* p_Player = (CBase*)ADR_PLAYERPOINTER;
CMatrix* p_Matrix = (CMatrix*)ADR_MATRIX;
CServerBase* p_Server = (CServerBase*)ADR_SERVERPOINTER;


CServer* getServer()
{
return p_Server->MyServer;
}

#define STANDS 0x01
#define KNEES 0x02
#define PRONES 0x03
#define LEANS_LEFT 0x04
#define LEANS_RIGHT 0x05
#define RUNS 0x06
#define ROLLS 0x07
#define TURNLEFT 0x08
#define TURNRIGHT 0x09
#define GOESBACKWARDS 0x10
#define GOESFORWARDS 0x11
#define UNKNOWN 0x12
#define LADDER 0x13
#define JUMPS 0x14
#define PRONES_LEANS_LEFT 0x15
#define PRONES_LEANS_RIGHT 0x16
#define KNEES_LEANS_LEFT 0x17
#define KNEES_LEANS_RIGHT 0x18
#define SWIMS 0x19
#define ANIMATION 0x20
#define ZOMBIE_STANDING 0x21
#define ZOMBIE_WALKING 0x22
#define VEHICLE 0x23
#define PI 3.14159265f
#define RADTODEG(radian) ((180.0f / PI) * (radian))
#define DEGTORAD(degree) ((PI / 180.0f) * (degree)) 
#define GETSTATE GetState(p_Player->pGlobal[dwIndex])
#define GETYAW p_Player->pGlobal[dwIndex]->Yaw
#define YAWCORRECTION sin(DEGTORAD(GETYAW)) 
#define GETPITCH sin(DEGTORAD(p_Player->pGlobal[dwIndex]->Pitch))

FLOAT GetDistance(CPlayer* pLocal, CPlayer* pGLobal)
{
    FLOAT angle[3];
    angle[0] = pGLobal->ViewX - pLocal->PosX;
    angle[1] = pGLobal->ViewY - pLocal->PosY;
    angle[2] = pGLobal->ViewZ - pLocal->PosZ;
    return sqrt(angle[0]*angle[0]+angle[1]*angle[1]+angle[2]*angle[2]);
}

BYTE GetState( CPlayer* pGlobal)
{
 BYTE myState = pGlobal->PlayerState;
 if (myState == 0x47 || myState == 0xF  )
 {
        return STANDS;  
 }
    else if (myState == 0x57 || myState == 0x5D || myState == 0x5C || myState == 0x5E || myState == 0x5F )
 {
        return KNEES;    
 }
  else if (myState == 0x38 || myState == 0x3C || myState == 0x3B || myState == 0x3D || myState == 0x3E )
 {
    return PRONES;
 }
    else if (myState == 0x58 )
 {
        return KNEES_LEANS_LEFT;
 }
    else if (myState == 0x59 )
 {
        return KNEES_LEANS_RIGHT;
 }
    else if (myState == 0x3A )
 {
        return PRONES_LEANS_RIGHT;
 }
    else if (myState == 0x39 )
 {
        return PRONES_LEANS_LEFT;
 }
    else if (myState == 0x48 )
 {
        return LEANS_LEFT;
 }
    else if (myState == 0x49 )      
 {
        return LEANS_RIGHT;  
 }
    else if (myState == 0x46 )
 {
        return RUNS;
 }
    else if (myState == 0x25 || myState == 0x24 || myState == 0x26 || myState == 0x27 )
 {
        return ROLLS;
 }
    else if (myState == 0x4C )
 {
        return TURNLEFT;
 }
    else if (myState == 0x4D )
 {
        return TURNRIGHT;
 }
    else if (myState == 0x4A )
 {
        return GOESBACKWARDS;
 }
    else if (myState == 0x4B || myState == 0x12 )
 {
        return GOESFORWARDS;
 }
    else if (myState == 0x36 || myState == 0x37 )
 {
        return LADDER;
 }
    else if (myState == 0x54 || myState == 0x56 || myState == 0x55 )
 {
        return JUMPS;
 }
    else if (myState == 0xFE )
 {
        return SWIMS;
 }
    else if (myState == 0x2A || myState == 0x2B || myState == 0x2C || myState == 0x2D || myState == 0x2E )
 {
        return ANIMATION;
 }
    else if (myState == 0xF )
 {
        return ZOMBIE_STANDING;
 }
    else if (myState == 0x12 )
 {
        return ZOMBIE_WALKING;
 }
    return UNKNOWN;
}

bool IsAnEnemy(int index)
{
 int MyTeamID = GetGlobalInfo(GetLocalInfo())->TEAM;

 if(GetGlobalInfo(index)->TEAM == 1 || GetGlobalInfo(index)->TEAM == 0)
 {
if(GetGlobalInfo(index)->TEAM != MyTeamID)
return true;
else
return false;
 }
}

int GetNearestPlayer()
{
 int MyIndex = 0;
 float MyDistance = 0; 
 float MaxDistance = 0;
 switch (cAimbot.CH_AimDistance )
 {
  case 1: MaxDistance = 1000; break;
  case 2: MaxDistance = 100000; break;
  case 3: MaxDistance = 10000000; break;
 }
 for (int MaxPlayer = 0; MaxPlayer < 32; MaxPlayer++)
 {
  DWORD dwServerPtr = ADR_SERVERPOINTER;
  CPlayerInfo *pInfo = GetGlobalInfo(MaxPlayer);
    CPlayerInfo *pLocalInfo = GetGlobalInfo(p_Player->pLocal->index);
  if (MaxPlayer != *(INT*)(dwServerPtr+OFS_LOCALSIZE) )
  {

   if (cAimbot.CH_AimEnemy == 1 && pInfo->TEAM == pLocalInfo->TEAM)
   {
   }
   else
   {
    if (GetGlobalInfo(MaxPlayer)->HEALTH > 0 )
    {
     if (GetGlobalInfo(GetLocalInfo())->TEAM != GetGlobalInfo(MaxPlayer)->TEAM)
     {

      MyDistance = GetDistance(p_Player->pLocal,p_Player->pGlobal[MaxPlayer]);
      if (MyDistance < MaxDistance )
      {
       MaxDistance = MyDistance;
       MyIndex = MaxPlayer;
      }
     }
    }
   }
  }
 }
 return MyIndex;
}
int GetCrossHairPlayer()
{
 int MyIndex = 0;
 float MyFOV = 0; 
 float MaxFOV = 0; 
 switch (cAimbot.CH_AimDistance )
 {
  case 1: MaxFOV = 1000; break;
  case 2: MaxFOV = 100000; break;
  case 3: MaxFOV = 10000000; break;
 }
 for (int MaxPlayer = 0; MaxPlayer < 32; MaxPlayer++)
 {  
  DWORD dwServerPtr = ADR_SERVERPOINTER;
  CPlayerInfo *pInfo = GetGlobalInfo(MaxPlayer);
     CPlayerInfo *pLocalInfo =  GetGlobalInfo(p_Player->pLocal->index);
  if (MaxPlayer != *(INT*)(dwServerPtr+OFS_LOCALSIZE) )
  {

   if (cAimbot.CH_AimEnemy == 1 && pInfo->TEAM == pLocalInfo->TEAM)
   {
   }
   else
   {
    if (GetGlobalInfo(GetLocalInfo())->TEAM != GetGlobalInfo(MaxPlayer)->TEAM)
    {
     if (pInfo->HEALTH > 0)
     {
      float angleYaw = (p_Local->Yaw) - ((atan2(p_Player->pGlobal[MaxPlayer]->ViewZ - p_Player->pLocal->ViewZ,p_Player->pGlobal[MaxPlayer]->ViewX - p_Player->pLocal->ViewX) * 180 / PI) - 90);
      float anglePitch = ((p_Local->Pitch) - ( -1 * atan( (p_Player->pGlobal[MaxPlayer]->ViewY - p_Local->PosY)/sqrt( ((p_Player->pGlobal[MaxPlayer]->ViewX - p_Local->PosX) * (p_Player->pGlobal[MaxPlayer]->ViewX - p_Local->PosX)) + ((p_Player->pGlobal[MaxPlayer]->ViewZ - p_Local->PosZ) * (p_Player->pGlobal[MaxPlayer]->ViewZ - p_Local->PosZ)))) * 180 / PI ));
      if (angleYaw < 0)
      {
       angleYaw *= -1;
      }
      if (anglePitch < 0)
      {
       anglePitch *= -1;
      }
      MyFOV = angleYaw + anglePitch;
      if (MyFOV < MaxFOV )                
      {       
       MaxFOV = MyFOV;
       MyIndex = MaxPlayer;                  
      }
     }
    }
   }
  }
 }
 return MyIndex;
}


FLOAT CalculatePitch(INT dwIndex)
{
 FLOAT AngelX = p_Player->pGlobal[dwIndex]->ViewX - p_Local->PosX;
 FLOAT AngelY = p_Player->pGlobal[dwIndex]->ViewY - p_Local->PosY;
 FLOAT AngelZ = p_Player->pGlobal[dwIndex]->ViewZ - p_Local->PosZ;
 FLOAT PitchCorrection = 0;
 if (GETSTATE == STANDS || GETSTATE == RUNS || GETSTATE == GOESFORWARDS|| GETSTATE == GOESBACKWARDS || GETSTATE == TURNRIGHT ||  GETSTATE == TURNLEFT || GETSTATE == LEANS_LEFT ||  GETSTATE == LEANS_RIGHT )
 {
  PitchCorrection = 30.5f; 
 }
 else if (GETSTATE == PRONES)
 {
  PitchCorrection = 3.5f;
 }
 else if (GETSTATE == KNEES)
 {
  PitchCorrection = 26.0f;
 }
 if (GETSTATE == LEANS_LEFT || GETSTATE == LEANS_RIGHT)
 {
  PitchCorrection -= 2.0f;
 }
 else if (GETSTATE == KNEES_LEANS_LEFT || GETSTATE == KNEES_LEANS_RIGHT)
 { 
  PitchCorrection -= 2.0f;
 }
 if (GETSTATE == UNKNOWN)
 {
  PitchCorrection = 28.0f;
 }
 if (GETSTATE == ZOMBIE_STANDING)
 {
  PitchCorrection = 29.0f;
 }
 if (GETSTATE == ZOMBIE_WALKING)
 {
  PitchCorrection = 28.0f;
 }
 if (GETPITCH < 0)
 { 
  PitchCorrection -= (6.5f * GETPITCH);
 }
 else if (GETPITCH > 0)
 {
  PitchCorrection -= (3.0f * GETPITCH);
 }
    return float( -1 * (atan( (AngelY + PitchCorrection) / sqrt( AngelX * AngelX + AngelZ * AngelZ )) * 180 / M_PI ) );
}

 FLOAT CalculateYaw(INT dwIndex)
{
 FLOAT ViewX = p_Player->pGlobal[dwIndex]->ViewX - p_Player->pLocal->ViewX;
 FLOAT ViewZ = p_Player->pGlobal[dwIndex]->ViewZ - p_Player->pLocal->ViewZ;
 FLOAT YawCorrection = 0;
 if (YawCorrection == LEANS_LEFT)
 {
  YawCorrection -= (3.5f * YAWCORRECTION);
 }
 else if (GETSTATE == LEANS_RIGHT)
 {
  YawCorrection += (3.5f * YAWCORRECTION);
 }
 else if (GETSTATE == KNEES_LEANS_LEFT)
 {
  YawCorrection -= (3.0f * YAWCORRECTION);
 }
 else if (GETSTATE == KNEES_LEANS_RIGHT)
 {
  YawCorrection += (3.0f * YAWCORRECTION);
 }
 return float(RADTODEG(atan2(ViewZ+YawCorrection,ViewX))-90);
}


#pragma optimize("",on)
#endif