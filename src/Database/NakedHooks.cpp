#include "pch.h"
#include "CHook.h"
#include <PEHook.h>
bool CHook::StartupNakeds()
{
	DWORD dwOldProtectFlag_text{};
	int MAIN_MODULE_IMAGEBASE = 0x401000;
	IMAGE_NT_HEADERS32* peHeader = (IMAGE_NT_HEADERS32*)(MAIN_MODULE_IMAGEBASE + ((IMAGE_DOS_HEADER*)MAIN_MODULE_IMAGEBASE)->e_lfanew);
	VirtualProtect((void*)(peHeader->OptionalHeader.BaseOfCode + MAIN_MODULE_IMAGEBASE), peHeader->OptionalHeader.SizeOfCode, PAGE_READWRITE, &dwOldProtectFlag_text);



	VirtualProtect((void*)(peHeader->OptionalHeader.BaseOfCode + MAIN_MODULE_IMAGEBASE), peHeader->OptionalHeader.SizeOfCode, dwOldProtectFlag_text, &dwOldProtectFlag_text);
	return true;
}
