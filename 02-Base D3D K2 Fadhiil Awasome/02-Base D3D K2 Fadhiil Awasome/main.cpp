#include <Windows.h>

/*********************************************************************************************************************************************/
BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
    DisableThreadLibraryCalls(hDll);
    if (dwReason == DLL_PROCESS_ATTACH)
    /*CheckValidHardwareID();*/
    {
		MessageBox(0, "Mikazu-C2 D3D FullhacX", "Dimas Syahputra", MB_OK + MB_ICONWARNING );
		MessageBox(0, "Jangan rename DLL , Nanti Erorr nd Kompi lu gue restartt", "Dimas Syahputra", MB_OK + MB_ICONSTOP );
  /*      CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)D3Dhook, NULL, NULL, NULL);
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)D3Dhook1, NULL, NULL, NULL);
          CreateThread(0, 0, (LPTHREAD_START_ROUTINE)BeginHack,0, 0, 0);*/
  Sleep (5);
		}
		return true;
}