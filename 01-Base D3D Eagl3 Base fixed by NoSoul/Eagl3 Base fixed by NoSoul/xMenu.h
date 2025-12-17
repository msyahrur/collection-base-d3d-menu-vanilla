#ifndef _D3DMenu_H
#define _D3DMenu_H

#include <stdio.h>
#include <math.h> 
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "xFont.h"
#include "xColor.h"


#ifndef D3DFONT_RIGHT
#define D3DFONT_RIGHT	0x0008
#endif
#ifndef D3DFONT_SHADOW
#define D3DFONT_SHADOW	0x0010
#endif

#define GROUP		1
#define TEXT		2
#define ITEM		3
#define SUBGROUP		4

#define MCOLOR_TITLE	0xffff1111
#define MCOLOR_CURRENT	YELLOW
#define MCOLOR_GROUP	RED
#define MCOLOR_TEXT		WHITE
#define MCOLOR_OFF		GREY
#define MCOLOR_ON		WHITE
typedef struct {
  int  typ;		
  char *txt;	 
  char **opt;	 
  int  *var;	
  int  maxval;   
} tMENU;

class D3DMenu
{
public:
	D3DMenu(char *Name=0, int maxentries=99, int maxwidth=150)
	{
		title=Name;
		maxitems=maxentries;
		cur=noitems=visible=0;
		x=y=15;
		totwidth=ofs=maxwidth;
		height=15;
		titleheight=totheight=height+4;
		col_title  =MCOLOR_TITLE;
		col_group  =MCOLOR_GROUP;
		col_text   =MCOLOR_TEXT;
		col_off    =MCOLOR_OFF;
		col_on     =MCOLOR_ON;
		col_current=MCOLOR_CURRENT;
		MENU=(tMENU **)malloc(4*maxitems);
		for (int i=0; i<maxitems; i++) MENU[i]=(tMENU *)malloc(sizeof(tMENU));
	}
	~D3DMenu() {
		for (int i=0; i<maxitems; i++) free(MENU[i]);
		free(MENU);
	}
	DWORD		col_title;
	DWORD		col_group;
	DWORD		col_text;
	DWORD		col_off;
	DWORD		col_on;
	DWORD		col_current;

	int			x,y;
	int			totwidth,totheight;	
	int			height;	
	int		YPOS;
	int			titleheight;	
	int			ofs;			
	char		*title;		
	int 		cur;				
	int 		noitems;			
	int			visible;			

	tMENU		**MENU;
	
	void menuitem (char *txt, int *var, char **opt, int maxvalue=2, int typ=ITEM);
	void menugroup(char *txt, int *var, char **opt, int maxvalue=2);
	void menusubgroup(char *txt, int *var, char **opt, int maxval=2);
	void AddText (char *txt, char *opt="");
	void DrawTextC(int x,int y,DWORD color,char *text, ID3DXFont*  pFont1);
	void DrawTextR(int x,int y,DWORD color,char *text, ID3DXFont*  pFont1);
	void DrawTextL(int x,int y,DWORD color,char *text, ID3DXFont*  pFont1);
	void MenuShow(float x, float y,	ID3DXFont*  pFont, LPDIRECT3DDEVICE9 pDevice);
	void MenuNav(void);

private:
	int			maxitems;
};

#endif
