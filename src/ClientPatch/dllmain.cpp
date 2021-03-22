// dllmain.cpp : Define o ponto de entrada para o aplicativo DLL.
#include "pch.h"
#include "protection.h"
#include "HookMgr.h"
#include <cstdio>
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        HideModule(hModule);
        g_DllInst = hModule;

#ifdef _LOCAL_CLIENT
        if (AllocConsole())
        {
            if (freopen("CONOUT$", "w", stdout) != nullptr)
            {
                SetConsoleTitle("Spirit Destiny - Debug Console");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                printf("[DEBUG MODE]\n");
            }
        }
#endif
        IMAGE_DOS_HEADER* imageDosHeader = reinterpret_cast<IMAGE_DOS_HEADER*>(hModule);
        g_ImageNtHeaders = reinterpret_cast<IMAGE_NT_HEADERS*>(((BYTE*)imageDosHeader + imageDosHeader->e_lfanew));
        if (!HookMgr::InitializeConstants() || !HookMgr::InitializeNakeds())
            return false;

        return true;

    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
    {
        FreeLibrary(hModule);
        break;
    }
    }
    return TRUE;
}

