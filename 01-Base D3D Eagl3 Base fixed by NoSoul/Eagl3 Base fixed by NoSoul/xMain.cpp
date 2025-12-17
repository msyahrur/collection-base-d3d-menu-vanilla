#include <stdio.h>
#include "xBase.h"
#include "xDraw.h"
#include "xColor.h"
#include "xInt.h"
#include "xHack.h"
#include "xBase.h"
#include "xDetour.h"
#include "VTable.h"
oPresent	pPresent;
oDrawIndexedPrimitive       pDrawIndexedPrimitive;
ID3DXFont*  pFont;
VTableBase*GetVTable;
bool Color    = true;
D3DMenu	*xMenu=NULL;

void EMenu(pD3DdeviceX pDevice)
{
	if (xMenu==0) {							
	    xMenu = new D3DMenu("Eagl3 Public");
		xMenu->visible=1;										
		xMenu->col_title=RED;						
	} else {
		if (xMenu->noitems==0) menurebuild();
		if (xMenu->visible)
		{
	    BoxColor((float)12,(float)71,(float)153,(float)xMenu->noitems*xMenu->height+25,ColorBox,pDevice);
	//	BoxColor((float)12,(float)56,(float)145,(float)21,ColorBox,pDevice);
		BorderColor((float)12,71,(float)153,(float)xMenu->noitems*xMenu->height+25,1,YELLOW,pDevice);
		//BorderColor((float)12,56,(float)145,(float)21,1,YELLOW,pDevice);

		if(cMenu.infobox)
		{
			
				BoxColor(300,40,400,150,ColorBox,pDevice);
				BorderColor(300,40,400,150,1,YELLOW,pDevice);
				BoxColor(330,45,350,30,ColorBox,pDevice);
				BorderColor(330,45,350,30,1,YELLOW,pDevice);
				xMenu->DrawTextC(500,50,WHITE,"[ INFO BOX ]",pFont);
				BoxColor(330,75,350,30,ColorBox,pDevice);
				BorderColor(330,75,350,30,1,YELLOW,pDevice);
				xMenu->DrawTextC(480,80,WHITE,"Hack Working From :",pFont);
				xMenu->DrawTextC(550,80,GREEN,str,pFont);
				BoxColor(330,105,350,30,ColorBox,pDevice);
				BorderColor(330,105,350,30,1,YELLOW,pDevice);
				xMenu->DrawTextC(480,110,WHITE,"GuidTech : ",pFont);
				xMenu->DrawTextC(530,110,GREEN,"Verified!",pFont);
				BoxColor(330,135,350,30,ColorBox,pDevice);
				BorderColor(330,135,350,30,1,YELLOW,pDevice);
				xMenu->DrawTextC(480,140,WHITE,"Made by :",pFont);
				xMenu->DrawTextC(523,140,GREEN,"NoSoul",pFont);
				BoxColor(330,167,350,20,ColorBox,pDevice);
				BorderColor(330,167,350,20,1,YELLOW,pDevice);
				xMenu->DrawTextC(475,170,WHITE,"Date :",pFont);
				xMenu->DrawTextC(520,170,GREEN,sDATE,pFont);
			    
		}
		


		}
	    xMenu->MenuShow(12,10,pFont,pDevice);
		xMenu->MenuNav();
        //PlayerHacks();
        //ServerHacks();
	}
}
//==============================#Menu Addons=================================//

int astd=0;
int amin=0;
int asec=0;
void plussx()
{
	asec++;
	if (asec==60)
	{
		asec=0;amin++;
	}
	if (amin==60)
	{
		amin=0;astd++;
	}
	sprintf(str,"%d:%d:%d ",astd,amin,asec);
}
void zeitx(){for(;;){Sleep(1000);CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)plussx, NULL, NULL,0);}}
void Date(char *str,char *format)
{
struct tm * current_tm;
time_t current_time;
time (&current_time);
current_tm = localtime (&current_time);
sprintf( sDATE, "%02d.%d.%d",current_tm->tm_mday,current_tm->tm_mon+1,current_tm->tm_year-100+2000); //
}


void menurebuild(void)
{
	xMenu->menugroup(" [Menu Settings]",&group1,grp);
	if(group1)
	{
		xMenu->menuitem("  Exit WarRock",&cMenu.ExitWr,offon);
		xMenu->menuitem("  Panic Key(F5)",&cMenu.PanicKey,offon);
		xMenu->menuitem("  Info Box ",&cMenu.infobox,offon);
	}
	xMenu->menugroup(" [DirectX Related]",&group4,grp);
		if(group4)
		{
			xMenu->menuitem("  Chams",&Chams,comi);
			xMenu->menuitem("  No Fog",&NoFogg,offon);
			xMenu->menuitem("  Fullbright",&FullBright,offon);
			xMenu->menuitem("  Glasswalls",&GlassWalls,offon);
			xMenu->menuitem("  Crosshair",&Crosshaird3d,cross,8);


		}
   xMenu->menugroup(" [Player Related]" ,&group2,grp);
  if (group2) 
  {
   xMenu->menuitem("  Super Jmp",&cPlayer.superjmp,offon);
   xMenu->menuitem("  NoFallDamage",&cPlayer.NFD,offon);
   xMenu->menuitem("  Player Speed",&cPlayer.PlayerSpeed,speed,6);
   xMenu->menuitem("  Roll Speed",&cPlayer.CH_Speedroll,speed,6);
   xMenu->menuitem("  Full Stamina",&cPlayer.STAMINA,offon);
   xMenu->menuitem("  Instant Spawn",&cPlayer.NoSpawnWait,offon);
   xMenu->menuitem("  No Bounds",&cPlayer.CH_NoBounds,offon);
   xMenu->menuitem("  Fast Ammo",&cPlayer.FastAmmo,offon);
   xMenu->menuitem("  Fast Medic",&cPlayer.FastMedic,offon);
   xMenu->menuitem("  Fast Repair",&cPlayer.FastRepair,offon);
   xMenu->menuitem("  Fast Flag",&cPlayer.FastFlag,offon);
   xMenu->menuitem("  Player Drunk",&cPlayer.ImDrunk,offon);
   xMenu->menuitem("  Save Coordinate",&Savecord,offon);
   xMenu->menuitem("  Teleport",&Teleport,offon);
   xMenu->menuitem("  OPK",&cOPK.CH_OPK,offon);
   xMenu->menuitem("  SVP",&cOPK.CH_SVP,offon);
   xMenu->menuitem("  AntiOPK",&cOPK.AntiOpk,offon);
   xMenu->menuitem("  Invisible",&cServer.CH_Invisible,offon);
   xMenu->menuitem("  Walk T. Walls",&cPlayer.WTW,offon);
   xMenu->menuitem("  Auto(Ammo/Medic)",&cPlayer.AutoAmmoMedic,offon);
  }
  xMenu->menugroup(" [PX Items]",&PXRelated,grp);
  if(PXRelated)
  {

  }
  xMenu->menugroup(" [Server Related]",&group3,grp);
  if (group3)
  {
   xMenu->menuitem("  Premium",&cServer.Premium,prem,5);
   xMenu->menuitem("  Visual Lv.",&cServer.Level,Level,101);
   xMenu->menuitem("  Max Dinar",&cServer.Dinar,offon);
   xMenu->menuitem("  All Slots",&cServer.AllSlots,offon);
   xMenu->menuitem("  GM Warning",&cServer.CH_GM,warn,3);
   xMenu->menuitem("  Anti AFK Kick",&cPlayer.Antiafk,offon);
  }
  xMenu->menugroup(" [Weapon Related]",&group5,grp);
  if(group5)
  {
	  xMenu->menuitem("  No Recoil",&cWeapon.CH_NORECOIL,offon);
	  xMenu->menuitem("  No Spread",&cWeapon.CH_NoSpread,offon);
	  xMenu->menuitem("  Super No Spread",&cWeapon.CH_SUPERNOSPREAD,offon);
	  xMenu->menuitem("  Bullet",&cWeapon.CH_Bullets,offon);
	  xMenu->menuitem("  BoneShoot",&cWeapon.CH_BoneShot,offon);
	  xMenu->menuitem("  Autoshoot",&cBot.CH_AutoShot,offon);
	  xMenu->menuitem("  Quick Plant/Defuse",&cWeapon.CH_QUICKPLANT,offon);
	  xMenu->menuitem("  No Reload",&cWeapon.CH_NoReload,offon);
	  xMenu->menuitem("  No Delay",&cWeapon.CH_NoDelay,offon);
	 // xMenu->menuitem("  Unlimited Ammo",&cWeapon.CH_Unlimitedammo,offon);
	  xMenu->menuitem("  Scope",&cWeapon.CH_Scope,offon);
  }

 
}




BOOL Create;
HRESULT WINAPI myPresent ( LPDIRECT3DDEVICE9 pDevice, CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion)
{


	if( !Create )
	{
		
 D3DXCreateFont(pDevice, 13, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, (LPCSTR)"Tahoma", &pFont);//Comic Sans MS,Nina,
		Create = true;
	}

	if( pFont == NULL )
		pFont->OnLostDevice();
	
	else
	EMenu(pDevice);
	DWORD dwCrossHairColor;
	switch (Crosshaird3d )
	{
	    case 1: dwCrossHairColor = RED; break;
		case 2: dwCrossHairColor = GREEN; break;
		case 3: dwCrossHairColor = BLUE; break;
		case 4: dwCrossHairColor = ORANGE; break;
		case 5: dwCrossHairColor = PURPLE; break;
		case 6: dwCrossHairColor = BLACK; break;
		case 7: dwCrossHairColor = WHITE; break;
	}
	if ( Crosshaird3d )
	{
		int PosX = (GetSystemMetrics(0)/2);
		int PosZ = (GetSystemMetrics(1)/2);
		D3DRECT Rect1 = {PosX-10,PosZ,PosX+10,PosZ+1};
		D3DRECT Rect2 = {PosX,PosZ-10,PosX+1,PosZ+10};
		pDevice->Clear(1,&Rect1,D3DCLEAR_TARGET,dwCrossHairColor,0,0); 
		pDevice->Clear(1,&Rect2,D3DCLEAR_TARGET,dwCrossHairColor,0,0);
	}
	

	
	
	return pPresent(pDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}


HRESULT WINAPI  myDrawIndexedPrimitive(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE pType D3DparamX,UINT nMinIndex, UINT nNumVertices, UINT nStartIndex, UINT nPrimitiveCount )
{
	_asm pushad;
	LPDIRECT3DVERTEXBUFFER9 Stream;
	UINT Offset = 0;
	UINT m_Stride = 0;
	if(pDevice->GetStreamSource(0, &Stream, &Offset, &m_Stride) == D3D_OK)
	Stream->Release();

	_asm popad;
   return pDrawIndexedPrimitive(pDevice,pType D3DparamvalX,nMinIndex,nNumVertices,nStartIndex,nPrimitiveCount);
}

HRESULT WINAPI myReset (LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters )
{
	pFont->OnLostDevice();
	HRESULT hRet = pReset(pDevice, pPresentationParameters);
	pFont->OnResetDevice();


    return hRet;
}



DWORD_PTR* FindDevice(DWORD Base,DWORD Len)
{
	unsigned long i = 0, n = 0;

	for( i = 0; i < Len; i++ )
	{
        if(*(BYTE *)(Base+i+0x00)==0xC7)n++;
	    if(*(BYTE *)(Base+i+0x01)==0x06)n++;
	    if(*(BYTE *)(Base+i+0x06)==0x89)n++;
	    if(*(BYTE *)(Base+i+0x07)==0x86)n++;	
        if(*(BYTE *)(Base+i+0x0C)==0x89)n++;
	    if(*(BYTE *)(Base+i+0x0D)==0x86)n++;

	    if(n == 6) return (DWORD_PTR*)
			(Base + i + 2);n = 0;
	}
	return(0);
}
int D3D(void)
{
	HINSTANCE	hD3D;
	DWORD		vTable[105];
	DWORD VTABLE_RESET=GetVTable->ID(RESET);
	hD3D=0;
	do {
		hD3D = GetModuleHandle("d3d9.dll");
		if (!hD3D) Sleep(10);
	} while(!hD3D);

	if (D3Ddiscover((void *)&vTable[0],420)==0) return 0;
	{

		pPresent = (oPresent)DetourCreate((DWORD)vTable[17], (DWORD)myPresent,12);
		pReset = (oReset)DetourCreate((DWORD)VTABLE_RESET,(DWORD)myReset,12);
			
		Sleep(100);
	}

	return 0;
}	

//int StartD3D(void)
//{
//
//	HMODULE hD3D = NULL;
//	do {
//		hD3D = GetModuleHandleA("d3d9.dll");
//		Sleep(10);
//	}while(!hD3D);
//
//	DWORD_PTR * VTablePtr = FindDevice((DWORD)hD3D,0x128000);
//
//    if(VTablePtr == NULL)
//	{
//		MessageBox(NULL,"D3DDevice Pointer Not Found!",0,MB_ICONSTOP);
//        ExitProcess(0);
//	}
//
//    DWORD_PTR * VTable = 0;
//    *(DWORD_PTR *)&VTable = *(DWORD_PTR *)VTablePtr;
//	pPresent              = (oPresent)	            DetourCreate((PBYTE)VTable[17], (PBYTE)myPresent,5);
//	 pReset = (oReset) DetourCreate((PBYTE)VTable[17],(PBYTE)myReset,5);/*((DWORD)dwReset, (DWORD)myReset, SIZEOF_JMP_REL);*/
//
//	return 0;
//}
VOID PlayerHackThread()
{
	while ( TRUE )
	{
		PlayerHacks();
		MenuHacks();
		ServerHacks();
		D3DHacks();
		WeaponHacks();
		//UNL_AMMO();
		BotHacks();
		Sleep(30);
	}
	
}
BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		HideModule(hModule);
		EraseHeaders(hModule); 
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)D3D, NULL, NULL, NULL);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)PlayerHackThread, NULL, NULL, NULL);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)OPKThread, NULL, NULL, NULL);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)zeitx, NULL, NULL, NULL);

	}

	return TRUE;
}

