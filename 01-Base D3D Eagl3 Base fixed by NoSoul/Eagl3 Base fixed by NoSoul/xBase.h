#ifndef _D3DBASE_H
#define _D3DBASE_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <time.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "xMenu.h"
#define D3Ddllname		"d3d9.dll"
#define pD3DdeviceX		LPDIRECT3DDEVICE9
#define pD3DvertexX		LPDIRECT3DVERTEXBUFFER9
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#define D3DparamX		, UINT paramx
#define D3DparamvalX	, paramx
typedef HRESULT (WINAPI * oPresent)              (LPDIRECT3DDEVICE9 pDevice, CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion);
typedef HRESULT (WINAPI * oDrawIndexedPrimitive) (LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE pType D3DparamX,UINT nMinIndex, UINT nNumVertices, UINT nStartIndex, UINT nPrimitiveCount );
typedef HRESULT (WINAPI* oReset) (LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);
oReset pReset;
void PreReset (pD3DdeviceX pDevice);
void PostReset(pD3DdeviceX pDevice);
bool bCompare(const BYTE* pData, const BYTE* bMask, const char* szMask);
DWORD FindPattern(DWORD dwAddress,DWORD dwLen,BYTE *bMask,char * szMask);
void *DetourCreate(BYTE *src, const BYTE *dst, const int len);
void menurebuild(void);
void EMenu(pD3DdeviceX pDevice);
extern bool Color;
extern int Chams;
extern int ChamsSel;
extern int Chams2;


#endif