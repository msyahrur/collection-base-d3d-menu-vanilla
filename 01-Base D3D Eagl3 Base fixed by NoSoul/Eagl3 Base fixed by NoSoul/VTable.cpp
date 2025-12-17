#include "vTable.h"
DWORD VTableBase::FindDevice(DWORD Len)
{
    DWORD dwObjBase = 0;
	dwObjBase = (DWORD)LoadLibraryA("D3D9.DLL");
    while (dwObjBase++ < dwObjBase + Len)
    {
        if ( (*(WORD*)(dwObjBase + 0x00)) == 0x06C7 && (*(WORD*)(dwObjBase + 0x06)) == 0x8689 && (*(WORD*)(dwObjBase + 0x0C)) == 0x8689) 
		{ 
			dwObjBase += 2; break;
		}
    }
    return( dwObjBase );
}
DWORD VTableBase::ID(INT index)
{
	PDWORD VTable;
    *(DWORD*)&VTable = *(DWORD*)FindDevice(0x128000);
	return VTable[index];
}