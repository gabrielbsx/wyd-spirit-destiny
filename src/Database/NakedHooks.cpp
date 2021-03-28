#include "pch.h"
#include "CHook.h"
#include <PEHook.h>
#include "ImportInfo.h"

bool CHook::StartupNakeds()
{

	try
	{
		PEHook::SETDWORD((DWORD)"./data%2.2d.csv", 0x004880FE + 1);

		PEHook::SETDWORD(15, 0x048D93F + 1);
		PEHook::SETDWORD(6500, 0x048F6FF + 6);

		//Change default directory
		PEHook::SETBYTE(0x90, 0x48F441);
		PEHook::SETDWORD((DWORD)"../../Imports/ImportItem/*.*", 0x48F442 + 1);
		PEHook::SETBYTE(8, 0x48F456 - 1);

		PEHook::SETBYTE(0x90, 0x48F4F9);
		PEHook::SETDWORD((DWORD)"../../Imports/ImportItem/%s", 0x48F4FA + 1);
		PEHook::SETBYTE(12, 0x48F50E - 1);

		PEHook::SETBYTE(0x90, 0x48F51B);
		PEHook::SETDWORD((DWORD)"../../Imports/err_ImportItem/%s", 0x48F51C + 1);
		PEHook::SETBYTE(12, 0x48F530 - 1);


		PEHook::SETBYTE(0x90, 0x48DE7D);
		PEHook::SETDWORD((DWORD)"../../Imports/Update/*.*", 0x48DE7E + 1);
		PEHook::SETBYTE(8, 0x48DE92 - 1);

		PEHook::SETBYTE(0x90, 0x48DF18);
		PEHook::SETDWORD((DWORD)"../../Imports/Update/%s", 0x48DF19 + 1);
		PEHook::SETBYTE(12, 0x48DF2D - 1);


		//Jmp IP Verify NPKO
		PEHook::SETBYTE(0x90, 0x48A839);
		PEHook::SETBYTE(0x90, 0x48A83A);

		PEHook::SETBYTE(0x90, 0x48A84E);
		PEHook::SETBYTE(0x90, 0x48A84F);

		// Ignore PK slot
		PEHook::SETBYTE(63, 0x048CC7E + 6);

		PEHook::JMP_NEAR(0x048D94A , ImportInfo::NKD_Modify);
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}
