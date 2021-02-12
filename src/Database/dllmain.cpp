// dllmain.cpp : Define o ponto de entrada para o aplicativo DLL.
#include "pch.h"
#include "CMain.h"
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		DisableThreadLibraryCalls(hModule);


		g_pMain = new CMain();

		return g_pMain->Initialize() ? TRUE : []() {
			MessageBox(0, "Failed on load Database.dll", "Failed on load", MB_OK | MB_ICONWARNING);
			return false;
		} ();
	}
	case DLL_THREAD_ATTACH:
	{
		break;
	}
	case DLL_THREAD_DETACH:
	{
		break;
	}
	case DLL_PROCESS_DETACH:
	{
		if (g_pMain != nullptr)
			g_pMain->~CMain();

		FreeLibrary(hModule);
		break;
	}
	}
	return TRUE;
}

