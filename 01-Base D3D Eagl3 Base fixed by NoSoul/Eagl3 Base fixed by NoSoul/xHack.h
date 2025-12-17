#include "xAddy.h"
#include "Structs.h"
void MEMwrite(void *adr, void *ptr, int size)
{
        DWORD dwback;
        VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &dwback);
        memcpy(adr,ptr,size);
        VirtualProtect(adr,size,dwback, &dwback);
}
template <typename T>void WriteMEM(void* adr,T Vaule,T *Input = NULL)
{
        if(Input == 0)
                MEMwrite((void*)adr,(void*)&Vaule,sizeof(T));
        else
                MEMwrite((void*)Input,(void*)adr,sizeof(T));
}

DWORD pKeyHook = (DWORD)GetProcAddress(GetModuleHandleA("User32.dll"),"PostMessageA")+5;
_declspec(naked)INT __stdcall PostMessage_new(HWND hWnd,int Msg,WPARAM wParam,LPARAM lParam)
{
	__asm
	{
		MOV EDI,EDI;
		PUSH EBP;
		MOV EBP,ESP;
		JMP pKeyHook;
	}
}
LPARAM GetLParam(int key)
{
	UINT Scancode;
	LPARAM LParam;
	Scancode = MapVirtualKey(key, 0);
	LParam = (Scancode << 16);
	return LParam;
}

void D3DHacks()
{
	DWORD PlayerPTR = *(DWORD*)ADR_PLAYERPOINTER;
	if(PlayerPTR!=0)
		if(NoFogg&&PlayerPTR)
{
WriteMEM<float>((void*)ADR_FARFOG,1166127104);
WriteMEM<float>((void*)ADR_NEARFOG,0);
}
		if (GlassWalls&&PlayerPTR)
{
WriteMEM<int>((void*)ADR_GLASSWALL,4);
}else{WriteMEM<int>((void*)ADR_GLASSWALL,0);}

		if(FullBright == 1)
 {
  WriteMEM<int>((void*)Adr_FullBright1,1092779973);
  WriteMEM<int>((void*)Adr_FullBright2,1092779973);
  WriteMEM<int>((void*)Adr_FullBright3,1092779973);
}
if(FullBright == 0)
{
 WriteMEM<int>((void*)Adr_FullBright1,1054661888);
 WriteMEM<int>((void*)Adr_FullBright2,1054661888);
 WriteMEM<int>((void*)Adr_FullBright3,1054661888);
}

}

void MenuHacks(void)
{
	if(cMenu.ExitWr)
	{
		ExitProcess(0);
	}

	if(cMenu.PanicKey)
		{
			if ( GetAsyncKeyState ( VK_F5 )&1)
		{
		ExitProcess(0);
	}
	}


}

int PosX;
int PosY;
int PosZ;
int Savecord;
int Teleport;



void PlayerHacks()
{
DWORD PlayerPTR = *(DWORD*)ADR_PLAYERPOINTER;
if(PlayerPTR != 0)
{

	if(cPlayer.NFD)
	{
*(float*)(PlayerPTR + OFS_NFD) = -20000;
	}

	if (Savecord == 1)
	{
PosX = *(float*)(PlayerPTR + OFS_X);
PosY = *(float*)(PlayerPTR + OFS_Y);
PosZ = *(float*)(PlayerPTR + OFS_Z);
		Sleep(200);
		Savecord = false;
	}
	if (Teleport == 1)
	{
*(float*)(PlayerPTR + OFS_X) = PosX;
*(float*)(PlayerPTR + OFS_Y) = PosY;
*(float*)(PlayerPTR + OFS_Z) = PosZ;
		Sleep(200);
		Teleport = false;
	}

	if(cPlayer.AutoAmmoMedic)
{
				WriteMEM<float>((void*)ADR_AUTOMEDICAMMO,9999.0f); //AGGIORNARE ADDY
				WriteMEM<float>((void*)ADR_FASTAMMO,20.0f);
				WriteMEM<float>((void*)ADR_FASTMEDIC,20.0f);
}

	if(cPlayer.superjmp == 1)
	{
		if ( GetAsyncKeyState ( VK_CONTROL ) )
		{

				p_Player->pLocal->PosY = 2500;
		}

	}




	if( cPlayer.PlayerSpeed == 0 )
	{
	p_Player->pLocal->PlayerSpeed = -10;
	}
	if( cPlayer.PlayerSpeed == 1 )
	{
	p_Player->pLocal->PlayerSpeed = -30;
	}
	if( cPlayer.PlayerSpeed == 2 )
	{
	p_Player->pLocal->PlayerSpeed = -60;
	}
	if( cPlayer.PlayerSpeed == 3 )
	{
	p_Player->pLocal->PlayerSpeed = -90;
	}
	if( cPlayer.PlayerSpeed == 4 )
	{
	p_Player->pLocal->PlayerSpeed = -120;
	}
	if( cPlayer.PlayerSpeed == 5 )
	{
	p_Player->pLocal->PlayerSpeed = -150;
	}


	if (cPlayer.STAMINA)
	{
		 if (PlayerPTR != 0)
       {
		   WriteMEM<float>((void*)ADR_STAMINA1,100);
		   WriteMEM<float>((void*)ADR_STAMINA2,100);
		   WriteMEM<float>((void*)ADR_STAMINA3,0);
		   WriteMEM<float>((void*)ADR_STAMINA4,0);
		   WriteMEM<float>((void*)ADR_STAMINA5,0);
		 }

	}
	if(cPlayer.WTW == 1)
{
 {*(float*)(PlayerPTR+OFS_Y) = (*(float*)(PlayerPTR+OFS_Y) +0.02);}
 {*(float*)(PlayerPTR+OFS_X) = (*(float*)(PlayerPTR+OFS_X) +0.02);}
 {*(float*)(PlayerPTR+OFS_Y) = (*(float*)(PlayerPTR+OFS_Y) -0.01);}
 {*(float*)(PlayerPTR+OFS_X) = (*(float*)(PlayerPTR+OFS_X) -0.01);}
}
	if (cPlayer.ImDrunk == 1)
{
*(DWORD*)(Adr_WorldInWater) = 2;
}else{
*(DWORD*)(Adr_WorldInWater) = 0;
}
	if (cPlayer.NoSpawnWait)
	{
		WriteMEM<double>((void*)ADR_NOSPAWNWAIT,0);
	}

	if (cPlayer.CH_Speedroll==0)
{
WriteMEM<float>((void*)ADR_ROOLSPEED,2);
}
if (cPlayer.CH_Speedroll==1)
{
WriteMEM<float>((void*)ADR_ROOLSPEED,4);
}
if (cPlayer.CH_Speedroll==2)
{
WriteMEM<float>((void*)ADR_ROOLSPEED,6);
}
if (cPlayer.CH_Speedroll==3)
{
WriteMEM<float>((void*)ADR_ROOLSPEED,8);
}
if (cPlayer.CH_Speedroll==4)
{
WriteMEM<float>((void*)ADR_ROOLSPEED,10);
}
if (cPlayer.CH_Speedroll==5)
{
WriteMEM<float>((void*)ADR_ROOLSPEED,20);
}
if (cPlayer.CH_Speedroll==6)
{
WriteMEM<float>((void*)ADR_ROOLSPEED,30);
}

if(cPlayer.Antiafk==1)
{
	WriteMEM<double>((void*)ADR_ANTIAFK,1);
}

if (cPlayer.CH_NoBounds)
            {
             *(long*)(ADR_NOBOUNDS1) = 0;
             *(long*)(ADR_NOBOUNDS2) = 0;
             *(long*)(ADR_NOBOUNDS3) = 0;
            }


if (cPlayer.FastAmmo)
{
	WriteMEM<float>((void*)ADR_FASTAMMO,20.0f);

}
if (cPlayer.FastMedic)
{
WriteMEM<float>((void*)ADR_FASTMEDIC,20.0f);
}
if (cPlayer.FastFlag)
{
WriteMEM<float>((void*)ADR_FASTFLAG,20.0f);
}
if (cPlayer.FastRepair)
{
WriteMEM<float>((void*)ADR_FASTREPAIR,20.0f);
}



}


}

void ServerHacks()
{
DWORD ServerPTR = *(DWORD*)ADR_SERVERPOINTER;



if(ServerPTR!= 0)
{
	char RenameMeifyouwant [50];
                char RenameMeIfyouWanttoo[333];
                                if(cServer.CH_GM==1)
                                {
                //                                char *RenameMeifyouwant =(char*) (ADR_GMWARNING);//                        RenameMe... = Addy ..                
                //                                if (strlen(RenameMeifyouwant)>2)
                //                                {
                //                                                sprintf(RenameMeIfyouWanttoo,  "WARNING :  GM Is In Room!!", ADR_GMWARNING); //Check Messege          
																//xMenu->DrawTextC(RED,400,400,RenameMeIfyouWanttoo,pFont);//BackGround So you can see messege better
                //                                }
                                }
								if(cServer.CH_GM==2) // Simple  if Admin logged = Get me Out
                                {
                                                char *RenameMeifyouwant = (char *) (ADR_GMWARNING);
                                                if         (strlen(RenameMeifyouwant ) > 2)
                                                {
                                                                ExitProcess(0);
                                                }
                                }
	switch ( cServer.CH_5Slot )
		{
			case 0: *(INT*)(ServerPTR+OFS_SLOT5) = 0; break;
			case 1: *(INT*)(ServerPTR+OFS_SLOT5) = 1; break;
		}
		switch ( cServer.CH_6Slot )
		{
			case 0: *(INT*)(ServerPTR+OFS_SLOT6) = 0; break;
			case 1: *(INT*)(ServerPTR+OFS_SLOT6) = 1; break;
		}
		switch ( cServer.CH_7Slot )
		{
			case 0: *(INT*)(ServerPTR+OFS_SLOT7) = 0; break;
			case 1: *(INT*)(ServerPTR+OFS_SLOT7) = 1; break;
		}
		switch ( cServer.CH_8Slot )
		{
			case 0: *(INT*)(ServerPTR+OFS_SLOT8) = 0; break;
			case 1: *(INT*)(ServerPTR+OFS_SLOT8) = 1; break;
		}

		if(cServer.AllSlots)
		{
			 *(INT*)(ServerPTR+OFS_SLOT5) = 1; 
			 *(INT*)(ServerPTR+OFS_SLOT6) = 1;
			 *(INT*)(ServerPTR+OFS_SLOT7) = 1;
			 *(INT*)(ServerPTR+OFS_SLOT8) = 1;

		}else{

		     *(INT*)(ServerPTR+OFS_SLOT5) = 0; 
			 *(INT*)(ServerPTR+OFS_SLOT6) = 0;
			 *(INT*)(ServerPTR+OFS_SLOT7) = 0;
			 *(INT*)(ServerPTR+OFS_SLOT8) = 0;

		}
		static bool InviciblePatch;

if (cServer.CH_Invisible)
{
if (!InviciblePatch)
{
*(long*)(ServerPTR+Mem_Invisible) -= 2;
InviciblePatch = true;
}
}
else
{
if (InviciblePatch)
{
*(long*)(ServerPTR+Mem_Invisible) += 2;
InviciblePatch = false;
}
}

			switch ( cServer.Premium )
		{
			case 0: *(INT*)(ServerPTR+OFS_PREMIUM) = 0; break;
			case 1: *(INT*)(ServerPTR+OFS_PREMIUM) = 1; break;
			case 2: *(INT*)(ServerPTR+OFS_PREMIUM) = 2; break;
			case 3: *(INT*)(ServerPTR+OFS_PREMIUM) = 3; break;
			case 4: *(INT*)(ServerPTR+OFS_PREMIUM) = 4; break;
		}
			switch(cServer.Dinar)
{
case 1:*(long*)(ServerPTR+OFS_DINAR) = 999999999;break;
}
				
switch(cServer.Level)
{
case 100:*(long*)(ServerPTR+OFS_LEVEL) = 37757475;break;
case 99:*(long*)(ServerPTR+OFS_LEVEL) = 36182475;break;
case 98:*(long*)(ServerPTR+OFS_LEVEL) = 34607475;break;
case 97:*(long*)(ServerPTR+OFS_LEVEL) = 33032475;break;
case 96:*(long*)(ServerPTR+OFS_LEVEL) = 31457475;break;
case 95:*(long*)(ServerPTR+OFS_LEVEL) = 29882475;break;
case 94:*(long*)(ServerPTR+OFS_LEVEL) = 28307475;break;
case 93:*(long*)(ServerPTR+OFS_LEVEL) = 26732475;break;
case 92:*(long*)(ServerPTR+OFS_LEVEL) = 25382475;break;
case 91:*(long*)(ServerPTR+OFS_LEVEL) = 24032475;break;
case 90:*(long*)(ServerPTR+OFS_LEVEL) = 22682475;break;
case 89:*(long*)(ServerPTR+OFS_LEVEL) = 21332475;break;
case 88:*(long*)(ServerPTR+OFS_LEVEL) = 19982475;break;
case 87:*(long*)(ServerPTR+OFS_LEVEL) = 18632475;break;
case 86:*(long*)(ServerPTR+OFS_LEVEL) = 17282475;break;
case 85:*(long*)(ServerPTR+OFS_LEVEL) = 15932475;break;
case 84:*(long*)(ServerPTR+OFS_LEVEL) = 15032475;break;
case 83:*(long*)(ServerPTR+OFS_LEVEL) = 14469975;break;
case 82:*(long*)(ServerPTR+OFS_LEVEL) = 13907475;break;
case 81:*(long*)(ServerPTR+OFS_LEVEL) = 13344975;break;
case 80:*(long*)(ServerPTR+OFS_LEVEL) = 12782475;break;
case 79:*(long*)(ServerPTR+OFS_LEVEL) = 12219975;break;
case 78:*(long*)(ServerPTR+OFS_LEVEL) = 11657475;break;
case 77:*(long*)(ServerPTR+OFS_LEVEL) = 11094975;break;
case 76:*(long*)(ServerPTR+OFS_LEVEL) = 10644975;break;
case 75:*(long*)(ServerPTR+OFS_LEVEL) = 10194975;break;
case 74:*(long*)(ServerPTR+OFS_LEVEL) = 9744975;break;
case 73:*(long*)(ServerPTR+OFS_LEVEL) = 9294975;break;
case 72:*(long*)(ServerPTR+OFS_LEVEL) = 8844975;break;
case 71:*(long*)(ServerPTR+OFS_LEVEL) = 8394975;break;
case 70:*(long*)(ServerPTR+OFS_LEVEL) = 7944975;break;
case 69:*(long*)(ServerPTR+OFS_LEVEL) = 7494975;break;
case 68:*(long*)(ServerPTR+OFS_LEVEL) = 7157475;break;
case 67:*(long*)(ServerPTR+OFS_LEVEL) = 6819975;break;
case 66:*(long*)(ServerPTR+OFS_LEVEL) = 6482475;break;
case 65:*(long*)(ServerPTR+OFS_LEVEL) = 6144975;break;
case 64:*(long*)(ServerPTR+OFS_LEVEL) = 5807475;break;
case 63:*(long*)(ServerPTR+OFS_LEVEL) = 5469975;break;
case 62:*(long*)(ServerPTR+OFS_LEVEL) = 5132475;break;
case 61:*(long*)(ServerPTR+OFS_LEVEL) = 4794975;break;
case 60:*(long*)(ServerPTR+OFS_LEVEL) = 4569975;break;
case 59:*(long*)(ServerPTR+OFS_LEVEL) = 4344975;break;
case 58:*(long*)(ServerPTR+OFS_LEVEL) = 4119975;break;
case 57:*(long*)(ServerPTR+OFS_LEVEL) = 3894975;break;
case 56:*(long*)(ServerPTR+OFS_LEVEL) = 3669975;break;
case 55:*(long*)(ServerPTR+OFS_LEVEL) = 3444975;break;
case 54:*(long*)(ServerPTR+OFS_LEVEL) = 3219975;break;
case 53:*(long*)(ServerPTR+OFS_LEVEL) = 3051225;break;
case 52:*(long*)(ServerPTR+OFS_LEVEL) = 2882475;break;
case 51:*(long*)(ServerPTR+OFS_LEVEL) = 2713725;break;
case 50:*(long*)(ServerPTR+OFS_LEVEL) = 2544975;break;
case 49:*(long*)(ServerPTR+OFS_LEVEL) = 2376225;break;
case 48:*(long*)(ServerPTR+OFS_LEVEL) = 2207475;break;
case 47:*(long*)(ServerPTR+OFS_LEVEL) = 2038725;break;
case 46:*(long*)(ServerPTR+OFS_LEVEL) = 1926225;break;
case 45:*(long*)(ServerPTR+OFS_LEVEL) = 1813725;break;
case 44:*(long*)(ServerPTR+OFS_LEVEL) = 1701225;break;
case 43:*(long*)(ServerPTR+OFS_LEVEL) = 1588725;break;
case 42:*(long*)(ServerPTR+OFS_LEVEL) = 1476225;break;
case 41:*(long*)(ServerPTR+OFS_LEVEL) = 1363725;break;
case 40:*(long*)(ServerPTR+OFS_LEVEL) = 1251225;break;
case 39:*(long*)(ServerPTR+OFS_LEVEL) = 1172475;break;
case 38:*(long*)(ServerPTR+OFS_LEVEL) = 1093725;break;
case 37:*(long*)(ServerPTR+OFS_LEVEL) = 1014975;break;
case 36:*(long*)(ServerPTR+OFS_LEVEL) = 936225;break;
case 35:*(long*)(ServerPTR+OFS_LEVEL) = 857475;break;
case 34:*(long*)(ServerPTR+OFS_LEVEL) = 778725;break;
case 33:*(long*)(ServerPTR+OFS_LEVEL) = 722475;break;
case 32:*(long*)(ServerPTR+OFS_LEVEL) = 666225;break;
case 31:*(long*)(ServerPTR+OFS_LEVEL) = 609975;break;
case 30:*(long*)(ServerPTR+OFS_LEVEL) = 553725;break;
case 29:*(long*)(ServerPTR+OFS_LEVEL) = 497475;break;
case 28:*(long*)(ServerPTR+OFS_LEVEL) = 441225;break;
case 27:*(long*)(ServerPTR+OFS_LEVEL) = 414225;break;
case 26:*(long*)(ServerPTR+OFS_LEVEL) = 387225;break;
case 25:*(long*)(ServerPTR+OFS_LEVEL) = 360225;break;
case 24:*(long*)(ServerPTR+OFS_LEVEL) = 333225;break;
case 23:*(long*)(ServerPTR+OFS_LEVEL) = 306225;break;
case 22:*(long*)(ServerPTR+OFS_LEVEL) = 279225;break;
case 21:*(long*)(ServerPTR+OFS_LEVEL) = 256725;break;
case 20:*(long*)(ServerPTR+OFS_LEVEL) = 234225;break;
case 19:*(long*)(ServerPTR+OFS_LEVEL) = 211725;break;
case 18:*(long*)(ServerPTR+OFS_LEVEL) = 189225;break;
case 17:*(long*)(ServerPTR+OFS_LEVEL) = 166725;break;
case 16:*(long*)(ServerPTR+OFS_LEVEL) = 148725;break;
case 15:*(long*)(ServerPTR+OFS_LEVEL) = 130725;break;
case 14:*(long*)(ServerPTR+OFS_LEVEL) = 112725;break;
case 13:*(long*)(ServerPTR+OFS_LEVEL) = 94725;break;
case 12:*(long*)(ServerPTR+OFS_LEVEL) = 76725;break;
case 11:*(long*)(ServerPTR+OFS_LEVEL) = 67950;break;
case 10:*(long*)(ServerPTR+OFS_LEVEL) = 59175;break;
case 9:*(long*)(ServerPTR+OFS_LEVEL) = 50400;break;
case 8:*(long*)(ServerPTR+OFS_LEVEL) = 41625;break;
case 7:*(long*)(ServerPTR+OFS_LEVEL) = 32850;break;
case 6:*(long*)(ServerPTR+OFS_LEVEL) = 24750;break;
case 5:*(long*)(ServerPTR+OFS_LEVEL) = 16650;break;
case 4:*(long*)(ServerPTR+OFS_LEVEL) = 11250;break;
case 3:*(long*)(ServerPTR+OFS_LEVEL) = 6750;break;
case 2:*(long*)(ServerPTR+OFS_LEVEL) = 2250;break;
case 1:*(long*)(ServerPTR+OFS_LEVEL) = 0;break;
}




	
}//PTR End
}//VOID End


void WeaponHacks (void)
{
	
	DWORD PlayerPTR = *(DWORD*)ADR_PLAYERPOINTER;
	if(PlayerPTR !=0)
	{
		if(cWeapon.CH_NORECOIL)
		{
			*(float*)(PlayerPTR+OFS_NORECOIL1) = 0;
		*(float*)(PlayerPTR+OFS_NORECOIL2) = 0;
		*(float*)(PlayerPTR+OFS_NORECOIL3) = 0;
		}
		switch ( cWeapon.CH_NoSpread )
		{
		    case 0: *(FLOAT*)(PlayerPTR+Ofs_NoSpread) = 0; break;
			case 1: *(FLOAT*)(PlayerPTR+Ofs_NoSpread) = 1; break;
		}
		if(cWeapon.CH_SUPERNOSPREAD)
		{
			WriteMEM<double>((void*)Adr_SuperNoSpread,0);
		}else{
			WriteMEM<double>((void*)Adr_SuperNoSpread,5);
		}
		if ( cWeapon.CH_Scope )
		{
			if ( GetAsyncKeyState ( VK_RBUTTON ) )
			{
				*(INT*)(ADR_SCOPE) = 1;
			}
			else if ( ! GetAsyncKeyState ( VK_RBUTTON ) )
			{
				*(INT*)(ADR_SCOPE) = 5;
			}
		}
		if(cWeapon.CH_Bullets)
		{
			WriteMEM<float>((void*)ADR_STW,-999.0f);
		}else{
			WriteMEM<float>((void*)ADR_STW,0.0f);
		}

		if( cWeapon.CH_QUICKPLANT == 1)
		{
			WriteMEM<FLOAT>((void*)ADR_QUICKPLANTDEFUSE,9999.0f);
		}

		if( cWeapon.CH_BoneShot )
{
WriteMEM<double>((void*)ADR_BONESHOT,1235);
}
else
{
WriteMEM<double>((void*)ADR_BONESHOT,1.237e3);
}
		if(cWeapon.CH_NoDelay)
			{
				*(DWORD*)(PlayerPTR+Ofs_NoDelay) = -1;
			}

			if(cWeapon.CH_NoReload)
			{
				*(FLOAT*)(PlayerPTR+Ofs_NoReload) = 1.0F;
			}



	}//PTR End
}// void end



void OPKThread()
{
 for(;;)
 {
  DWORD PlayerPointer  = *(DWORD*)ADR_PLAYERPOINTER;
  if(PlayerPointer != 0 )
  {
   for(int i = 0; i < 32; i++)
   {
    if(!p_Player->pGlobal || !p_Player->pLocal) break;
    if(PlayerPointer == 0 ) break;
{*(float*)(PlayerPointer + OFS_NFD) = -99999999;}
  {*(float*)ADR_NOWATER1 = 0;
   *(float*)ADR_NOWATER2 = 0;}
    CPlayer* pPlayer = p_Player->pGlobal[i];
    CPlayerInfo *pInfo = GetGlobalInfo(i);

    if(pInfo && pPlayer)
    {
     if(PlayerPointer == 0 ) break;
         
	 if(cOPK.CH_OPK == 1)
      {
        if(PlayerPointer == 0 ) break;
        if( pInfo->HEALTH > 0 )
        {
         if(PlayerPointer == 0 ) break;
         pPlayer->PosX= 0;
         pPlayer->PosY = 0;
         pPlayer->PosZ = 0; 
        }
      }
      if(cOPK.CH_SVP == 1)
      {
      DWORD Player = *(DWORD*)ADR_PLAYERPOINTER;
      if(Player != 0)
      {
      *(float*)(Player+OFS_Y) = 0;
      *(float*)(Player+OFS_X) = 0;
      *(float*)(Player+OFS_Z) = 0;
      pPlayer->PosX = (i*15);
      pPlayer->PosY = (i*15);
      pPlayer->PosZ = (i*15);
      }
      }
      }
    }
   if ( cOPK.AntiOpk )
{
    *(FLOAT*)(PlayerPointer+OFS_X) = 0.0F;
    *(FLOAT*)(PlayerPointer+OFS_Y) = 0.0F;
    *(FLOAT*)(PlayerPointer+OFS_Z) = 0.0F;
}
   }
  }
 }

VOID BotHacks()
{
	DWORD dwPlayerPtr = *(DWORD*)ADR_PLAYERPOINTER;
	DWORD dwServerPtr = *(DWORD*)ADR_SERVERPOINTER;
	if ( cBot.CH_AutoEnter )
	{
		HWND wndWarRock = FindWindowA(0,"WarRock");
  		PostMessage_new(wndWarRock,WM_KEYDOWN,VK_RETURN,GetLParam(VK_RETURN));
	}
	if ( cBot.CH_AutoStart )
	{
		HWND wndWarRock = FindWindowA(0,"WarRock");
  		PostMessage_new(wndWarRock,WM_KEYDOWN,VK_F5,GetLParam(VK_F5));
	}
	if ( dwPlayerPtr != 0 )
	{
		if ( cBot.CH_AutoBomb )
		{
			if ( GetGlobalInfo(GetLocalInfo())->TEAM == 0 )
			{
			    *(SHORT*)(dwPlayerPtr+Ofs_Weapon1) = 91;
			    *(SHORT*)(dwPlayerPtr+Ofs_Weapon2) = 91;
				*(SHORT*)(dwPlayerPtr+Ofs_Weapon3) = 91;
			}
		}
		if ( cBot.CH_AutoNipper )
		{
			if ( GetGlobalInfo(GetLocalInfo())->TEAM == 1 )
			{
			    *(SHORT*)(dwPlayerPtr+Ofs_Weapon1) = 118;
			    *(SHORT*)(dwPlayerPtr+Ofs_Weapon2) = 118;
				*(SHORT*)(dwPlayerPtr+Ofs_Weapon3) = 118;
			}
		}
		if ( cBot.CH_AutoSuicide )
		{
			*(FLOAT*)(dwPlayerPtr+OFS_NFD) = 99999.0F;
			cPlayer.NFD = 0;
		}
		if ( cBot.CH_AutoShot )
		{
			if ( *(SHORT*)(dwPlayerPtr+Ofs_Weapon2) != 118 && *(SHORT*)(dwPlayerPtr+Ofs_Weapon2) != 91 )
			{
				*(INT*)(dwPlayerPtr+OFS_WEAPONSTATE) = *(INT*)(ADR_WEAPONSHOOT);//Auto Shot
				*(DWORD*)(dwPlayerPtr+OFS_AUTOSHOOT) = 0;
			}
		}
		
	}
	
	}

DWORD dwCurVal,State = 0;
void UNL_AMMO()
{
 DWORD dwPlayer = *(DWORD*)(ADR_PLAYERPOINTER);
 DWORD dwServer = *(DWORD*)(ADR_SERVERPOINTER);
 if(cWeapon.CH_Unlimitedammo == 1)
 {
  if(dwPlayer != 0)
  {
   if(State == 0)
   {
    dwCurVal = *(DWORD*)(Mem_UnlAmmo);
    State = 1;
   }else if(State == 1)
   {
    *(DWORD*)(Mem_UnlAmmo) = 0;
   }
  }
 }

 if(GetAsyncKeyState(VK_ESCAPE)){ cWeapon.CH_Unlimitedammo = 0; State = 0;}

 if(cWeapon.CH_Unlimitedammo == 0)
 {
  if(dwPlayer != 0 && State == 1)
  {
   *(DWORD*)(Mem_UnlAmmo) = dwCurVal;
  }
 }
}

