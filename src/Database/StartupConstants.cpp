#include "..\GameServer\CHook.h"
#include "pch.h"
#include "CHook.h"
#include <PEHook.h>
bool CHook::StartupConstants()
{
	DWORD dwOldProtectFlag_text{};

	int MAIN_MODULE_IMAGEBASE = 0x401000;
	IMAGE_NT_HEADERS32* peHeader = (IMAGE_NT_HEADERS32*)(MAIN_MODULE_IMAGEBASE + ((IMAGE_DOS_HEADER*)MAIN_MODULE_IMAGEBASE)->e_lfanew);

	VirtualProtect((void*)(peHeader->OptionalHeader.BaseOfCode + MAIN_MODULE_IMAGEBASE), peHeader->OptionalHeader.SizeOfCode, PAGE_READWRITE, &dwOldProtectFlag_text);


	//Load basic files
	PEHook::SETDWORD((DWORD)"../../Common/Files/SkillData.csv", 0x0466448 + 1);
	PEHook::SETDWORD((DWORD)"../../Common/Files/Itemlist.csv", 0x0462E04 + 1);
	PEHook::SETDWORD((DWORD)"../../Common/Files/Extraitem.csv", 0x0462E3F + 1);
	PEHook::SETDWORD((DWORD)"../../Common/Files/Itemname.csv", 0x0462E6A + 1);
	PEHook::SETDWORD((DWORD)"../../Common/Files/InitItem.csv", 0x046616D + 1);
	PEHook::SETDWORD((DWORD)"../../Common/Files/AttributeMap.dat", 0x0467126 + 1);
	PEHook::SETDWORD((DWORD)"../../Common/Files/ItemEffect.h", 0x0463CD7 + 1);

	//Write files
	PEHook::SETDWORD((DWORD)"../../Common/Binary/itemname.bin", 0x0462F7A + 1);
	PEHook::SETDWORD((DWORD)"../../Common/Binary/extraitem.bin", 0x046333E + 1);

	//Load basemobs Mortal
	PEHook::SETDWORD((DWORD)"./npc/TransKnight", 0x0488ED6 + 1);
	PEHook::SETDWORD((DWORD)"./npc/Forema", 0x0488F3D + 1);
	PEHook::SETDWORD((DWORD)"./npc/BeastMaster", 0x0488FA4 + 1);
	PEHook::SETDWORD((DWORD)"./npc/Hunter", 0x048900B + 1);

	//Load basemobs Arch/Cele/Sub
	PEHook::SETDWORD((DWORD)"./npc/TransKnight2", 0x0489072 + 1);
	PEHook::SETDWORD((DWORD)"./npc/Forema2", 0x04890D9 + 1);
	PEHook::SETDWORD((DWORD)"./npc/BeastMaster2", 0x0489140 + 1);
	PEHook::SETDWORD((DWORD)"./npc/Hunter2", 0x04891A7 + 1);



	VirtualProtect((void*)(peHeader->OptionalHeader.BaseOfCode + MAIN_MODULE_IMAGEBASE), peHeader->OptionalHeader.SizeOfCode, dwOldProtectFlag_text, &dwOldProtectFlag_text);
	return true;
}

