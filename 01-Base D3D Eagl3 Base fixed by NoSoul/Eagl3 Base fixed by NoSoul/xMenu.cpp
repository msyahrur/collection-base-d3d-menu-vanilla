#include "xMenu.h"


void D3DMenu::menuitem(char *txt, int *var, char **opt, int maxval, int typ)
{
  if (noitems>=(maxitems-1)) return;
  MENU[noitems]->typ=typ;
  MENU[noitems]->txt=txt;
  MENU[noitems]->opt=opt;
  MENU[noitems]->var=var;
  MENU[noitems]->maxval=maxval;
  noitems++;
  totheight=(noitems*height)+titleheight;
}

void D3DMenu::menugroup(char *txt, int *var, char **opt, int maxval)
{
	menuitem(txt, var, opt, maxval, GROUP);
}

void D3DMenu::menusubgroup(char *txt, int *var, char **opt, int maxval)
{
	menuitem(txt, var, opt, maxval, SUBGROUP);
}
void D3DMenu::DrawTextR(int x,int y,DWORD color,char *text, ID3DXFont*  pFont1)
{
    RECT rect, rect2;
    SetRect( &rect, x, y, x, y );
	SetRect( &rect2, x - 0.1, y + 0.2, x - 0.1, y + 0. );
	pFont1->DrawTextA(NULL,text,-1,&rect2, DT_RIGHT|DT_NOCLIP,BLACK );
    pFont1->DrawTextA(NULL,text,-1,&rect, DT_RIGHT|DT_NOCLIP, color );
}
void D3DMenu::DrawTextL(int x,int y,DWORD color,char *text, ID3DXFont*  pFont1)
{
   
	RECT rect, rect2;
    SetRect( &rect, x, y, x, y );
	SetRect( &rect2, x - 0.1, y + 0.2, x - 0.1, y + 0. );
	pFont1->DrawTextA(NULL,text,-1,&rect2, DT_LEFT|DT_NOCLIP, BLACK
		);
    pFont1->DrawTextA(NULL,text,-1,&rect, DT_LEFT|DT_NOCLIP, color );
}

void D3DMenu::AddText(char *txt, char *opt)
{
	menuitem(txt,0,(char **)opt,0,TEXT);
}
void D3DMenu::DrawTextC(int x,int y,DWORD color,char *text, ID3DXFont*  pFont1)
{
    RECT rect, rect2;
    SetRect( &rect, x, y, x, y );
	SetRect( &rect2, x - 0.1, y + 0.2, x - 0.1, y + 0. );
	pFont1->DrawTextA(NULL,text,-1,&rect2, DT_CENTER|DT_NOCLIP, BLACK );
    pFont1->DrawTextA(NULL,text,-1,&rect, DT_CENTER|DT_NOCLIP, color );
}
//void D3DMenu::MenuShow(float x, float y,	ID3DXFont*  pFont1, LPDIRECT3DDEVICE9 pDevice)
//{
//	
//	 
//
//  int i, val,coloe;
//  DWORD color;
//  DWORD ColorQ;
//  DWORD ColorQQ;
//  char text[100];
//  if (!visible) return;
//
//
//  if (title[0])
//  {
//DrawTextC((x * 7) + 8, y + 62, RED, "<< MessageBox D3D >>", pFont1); // Your name cheats!
////DrawRectangle(pDevice,36,35,Mxofs-10,Mmax*Mysize-72 ,1,YELLOW);
//y+=(height+65);// Posizione y delle cartelle(Su-giù)
//  }
//  for (i=0; i<noitems; i++) 
//  {
//	  if (MENU[i]->typ==TEXT) 
//	  {
//		  sprintf(text, "%s", MENU[i]->txt);
//		   if (MENU[i]->opt) 
//		   {
//		  DrawTextR((x+ofs), y, color,(char *)MENU[i]->opt, pFont1);
//		   }
//
//  }else{
//
//	  val=(MENU[i]->var)?(*MENU[i]->var):0;
//	  if (i==cur)
//		  {
//              color=col_current;
//			  ColorQ=col_current;
//		  }
//		  else if(MENU[i]->typ==GROUP)
//		  {
//			  color=YELLOW;
//			  ColorQ=YELLOW;
//		  }
//		  else
//		  {
//			  color=(val)?WHITE:WHITE;
//			  ColorQ=(val)?GREEN:RED;
//		  }
//		  DrawTextR((x+ofs), y, color,(char *)MENU[i]->opt, pFont1);
//		  if (MENU[i]->opt) 
//		  {
//		  DrawTextR((x+ofs), y, ColorQ,(char *)MENU[i]->opt[val], pFont1);
//		  }
//
//		   y+=height;
//  }
//  YPOS=y;
//
//
//  }
//}


void D3DMenu::MenuShow(float x, float y,	ID3DXFont*  pFont1, LPDIRECT3DDEVICE9 pDevice)
{
	
	 

  int i, val,coloe;
  DWORD color;
  DWORD ColorQ;
  DWORD ColorQQ;
  char text[100];
  if (!visible) return;


  if (title[0])
  {
DrawTextC((x * 7) + 8, y + 62, RED, "<< Eagle Fixed >>", pFont1); // Your name cheats!
//DrawRectangle(pDevice,36,35,Mxofs-10,Mmax*Mysize-72 ,1,YELLOW);
y+=(height+65);// Posizione y delle cartelle(Su-giù)

  }
  for (i=0; i<noitems; i++)
  {
	   val=(MENU[i]->var)?(*MENU[i]->var):0;
	   coloe=(*MENU[i]->var);
	   
	   sprintf(text, "%s", MENU[i]->txt);
	    if (i==cur)
		  {
              color=RED;
			  ColorQ=RED;
		  }
		  else if(MENU[i]->typ==GROUP)
		  {
			  color=YELLOW;
			  ColorQ=YELLOW;
		  }
		  else
		  {
			  color=(val)?LightBlue:WHITE;
			  ColorQ=(val)?GREEN:RED;
		  }
	 //  if (i==cur)
	 //  {
		//   
		//color=RED;

		//   sprintf(text, "%s", MENU[i]->txt);
	 //  
	 //  }
	 //  else if (MENU[i]->typ==GROUP)
		//
  //         color=YELLOW;//Colore Cartelle
	 // 
  //
		//   
	 //  
  //     else if (MENU[i]->typ==TEXT)

  //         color=MCOLOR_TEXT;//Colore Funzione D3D9MENU->AddText("BLABLA");
	 //  else
		//   
		//   color=(val)?CYAN:WHITE;//Colore Funzioni ON/OFF 
	 //      ColorQ=(val)?GREEN:RED;
	  
	

	  // if(MENU[i]->typ == MENUITEM)
			//{
			//	rBox(40,y+4,7,7,(val)?GREEN:RED,pDevice);
			//	rRect(40,y+4,7,7,1,BLACKOP10,BLACKOP10,pDevice);
			////color=GREEN;//Colore Funzioni ON/OFF 
			//	
			//}
	  // if(MENU[i]->typ == MENUCAT)
			//{
			//	rBox(40,y+4,7,7,(val)?GREEN:RED,pDevice);
			//	rRect(40,y+4,7,7,1,BLACKOP10,BLACKOP10,pDevice);
			//	
			//}
	    

	   if (MENU[i]->opt) 
	   {
		   if (MENU[i]->typ==GROUP )
	         {
				DrawTextL(x+4, y, color,text, pFont1);//Posizione X delle Cartelle(sinistra-destra)
				y = y + 1,5;//Distanza fra le cartelle
		   }else{
				DrawTextL(x+6, y, color,text, pFont1);//Distanza delle funzioni quando si apre il menu
		   }
		   
	   }

	
	   
       if (MENU[i]->opt) 
	   {
		   if (MENU[i]->typ==TEXT)
			   DrawTextR((x+ofs), y, color,(char *)MENU[i]->opt, pFont1);
		   else
			   DrawTextR((x+ofs), y, ColorQ,(char *)MENU[i]->opt[val], pFont1);
	   }

       y+=height;
  }
  YPOS=y;


}



//void D3DMenu::MenuShow(float x, float y,	ID3DXFont*  pFont, LPDIRECT3DDEVICE9 pDevice)
//{
//  int	i,val,cy;
//  DWORD color;
//  DWORD texty;
//  DWORD ccolor;
//  char text[100];
// 
//  if (!visible) return;
//
//  cy=y;
//  if (title) {
//	  DrawTextC((float)(x + totwidth/2-4) ,(float)cy + 1 + 45, RED, "<<  Eagl3 Base Fixxed  >>", pFont); // Your name cheats!
//	  cy+=titleheight;
//  }
//  for (i=0; i<noitems; i++) 
//  {
//	  
//	     if (i==cur)
//	   {
//		   
//				
//		  
//  
//		color=col_current;
//			  texty=col_current;
//
//		   sprintf(text, "%s", MENU[i]->txt);
//	   
//	   }
//       else if (MENU[i]->typ==GROUP)
//		  
//           color=YELLOW;//Colore Cartelle
//		 //color=col_group;
//			//  /*texty=col_group;*/
//		   
//	   
//       else if (MENU[i]->typ==TEXT)
//           color=MCOLOR_TEXT;//Colore Funzione D3D9MENU->AddText("BLABLA");
//	   else
//		   
//		   color=(val)?CYAN:WHITE;//Colore Funzioni ON/OFF 
//	  
//	  /*val=(MENU[i]->var)?(*MENU[i]->var):0;
//		  if (i==cur){
//              color=col_current;
//			  texty=col_current;
//		  else if(MENU[i]->typ==GROUP)
//			  color=col_group;
//			  texty=col_group;
//		  else
//			  color=(val)?col_on:col_off;
//		  
//	  
//	  else  
//	  
//	  {*/
//
//		  
//	      
//		   if (MENU[i]->opt) 
//	   {
//		   if (MENU[i]->typ==GROUP )
//	         {
//				DrawTextL(x+33, y, color,text, pFont);//Posizione X delle Cartelle(sinistra-destra)
//				y = y + 1,5;//Distanza fra le cartelle
//		   }else{
//				DrawTextL(x+32, y, color,text, pFont);//Distanza delle funzioni quando si apre il menu
//		   }
//		   
//	   }
//	   if (MENU[i]->opt) 
//	   {
//		   if (MENU[i]->typ==TEXT)
//			   DrawTextR((x+ofs), y, color,(char *)MENU[i]->opt, pFont);
//		   else
//			   DrawTextR((x+ofs), y, color,(char *)MENU[i]->opt[val], pFont);
//	   }
//
//	 }
//     cy+=height;
//  }






void D3DMenu::MenuNav(void)
{
	if (GetAsyncKeyState(VK_INSERT)&1) visible=(!visible); 
  if (!visible)return ;
  if (GetAsyncKeyState(VK_F16) ) {
    if (GetAsyncKeyState(VK_UP)&1   ) y-=10;
    if (GetAsyncKeyState(VK_DOWN)&1 ) y+=10;
    if (GetAsyncKeyState(VK_LEFT)&1 ) x-=10;
    if (GetAsyncKeyState(VK_RIGHT)&1) x+=10;
  } else {
    if (GetAsyncKeyState(VK_UP)&1) {
		do {

			cur--;

			if (cur<0)  cur=noitems-1;
		} while (MENU[cur]->typ==TEXT);	
	} else if (GetAsyncKeyState(VK_DOWN)&1) {
		do {

			cur++;
		    if (cur==noitems) cur=0;
		} while (MENU[cur]->typ==TEXT);	
	} else if (MENU[cur]->var) {
		int dir=0;
		if (GetAsyncKeyState(VK_LEFT )&1 && *MENU[cur]->var > 0                    ) 
		{
			dir=-1;
		}
		if (GetAsyncKeyState(VK_RIGHT)&1 && *MENU[cur]->var < (MENU[cur]->maxval-1)) 
		{	
			dir=1; 
		}
		if (dir) {
			*MENU[cur]->var += dir;
			if (MENU[cur]->typ==GROUP) noitems=0; 
			if (MENU[cur]->typ==SUBGROUP) noitems=0;
		}
	}
  }
}