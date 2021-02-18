#include "pch.h"
#include "CHook.h"
#include <PEHook.h>
#include "CUser.h"
#include "CMob.h"
CUser* pUser;
CMob* pMob;
bool CHook::StartupConstants()
{
	DWORD dwOldProtectFlag_text{};

	int MAIN_MODULE_IMAGEBASE = 0x401000;
	IMAGE_NT_HEADERS32* peHeader = (IMAGE_NT_HEADERS32*)(MAIN_MODULE_IMAGEBASE + ((IMAGE_DOS_HEADER*)MAIN_MODULE_IMAGEBASE)->e_lfanew);

	VirtualProtect((void*)(peHeader->OptionalHeader.BaseOfCode + MAIN_MODULE_IMAGEBASE), peHeader->OptionalHeader.SizeOfCode, PAGE_READWRITE, &dwOldProtectFlag_text);

	pUser = reinterpret_cast<CUser*>(0x61AAAB4);
	pMob = reinterpret_cast<CMob*>(0x7D84AC0);
	//Load Hellgate infos
	PEHook::SETDWORD((DWORD)"./Settings/hellgate/HellGateRate_Weapon.txt", 0x04E4E3D + 1);
	PEHook::SETDWORD((DWORD)"./Settings/hellgate/HellGateRate_Armor.txt", 0x04E54CD + 1);
	PEHook::SETDWORD((DWORD)"./Settings/hellgate/HellGateRate_Accessory.txt", 0x04E5B3D + 1);


	// Load Map files
	PEHook::SETDWORD((DWORD)"../../Common/Files/heightmap.dat", 0x056BD1E + 1);
	PEHook::SETDWORD((DWORD)"../../Common/Files/AttributeMap.dat", 0x04C3CB6 + 1);
	PEHook::SETDWORD((DWORD)"../../Common/Files/InitItem.csv", 0x4C2CFD + 1);


	//Load items info
	PEHook::SETDWORD((DWORD)"../../Common/Files/ItemEffect.h", 0x04C0847 + 1);
	PEHook::SETDWORD((DWORD)"../../Common/Files/ItemList.csv", 0x04BF7B4 + 1);
	PEHook::SETDWORD((DWORD)"../../Common/Files/ExtraItem.csv", 0x04BF7EF + 1);
	PEHook::SETDWORD((DWORD)"../../Common/Files/ItemName.csv", 0x04BF81A + 1);

	///Load Skills Info
	PEHook::SETDWORD((DWORD)"../../Common/Files/SkillData.csv", 0x04C2FBD + 1);

	//Load Static Info
	PEHook::SETDWORD((DWORD)"./Settings/StaticData/lvitem.txt", 0x05177ED + 1);
	PEHook::SETDWORD((DWORD)"./Settings/StaticData/KhepraDropItem.txt", 0x057AA24 + 1);
	PEHook::SETDWORD((DWORD)"./Settings/StaticData/HadenStepitems.txt", 0x057AC5D + 1);
	PEHook::SETDWORD((DWORD)"./Settings/StaticData/ChristmasStepItems.txt", 0x057AE12 + 1);
	PEHook::SETDWORD((DWORD)"./Settings/StaticData/GameRoomDropList.txt", 0x058A0FD + 1);

	PEHook::SETDWORD((DWORD)"./Settings/BLOCKIP.txt", 0x04C491D + 1);
	PEHook::SETDWORD((DWORD)"./Settings/Chall.txt", 0x056C2C8 + 1);
	PEHook::SETDWORD((DWORD)"./Settings/Chall.txt", 0x056C383 + 1);
	PEHook::SETDWORD((DWORD)"./Settings/GameRoomIP.txt", 0x04C46AD + 1);
	PEHook::SETDWORD((DWORD)"./Settings/Guild.txt", 0x0512307 + 1);
	PEHook::SETDWORD((DWORD)"./Settings/Guild.txt", 0x05125A3 + 1);
	PEHook::SETDWORD((DWORD)"./Settings/IDprehibit.txt", 0x057ED0D + 1);
	PEHook::SETDWORD((DWORD)"./Settings/mobname.csv", 0x056BCE7 + 1);

	PEHook::SETDWORD(778, 0x64759C);
	PEHook::SETBYTE(0xEB, 0x0051B78E);

	VirtualProtect((void*)(peHeader->OptionalHeader.BaseOfCode + MAIN_MODULE_IMAGEBASE), peHeader->OptionalHeader.SizeOfCode, dwOldProtectFlag_text, &dwOldProtectFlag_text);
	return true;
}