#include "pch.h"
#include "HookMgr.h"
#include <exception>
#include "pe_Hook.h"
#include "Naked.h"

void HookMgr::ChangeWindowName()
{
	const char* windowName = "Spirit Destiny - https://spirit-destiny.com/";
	PEHook::SETDWORD((int)windowName, 0x05494FC + 1);
}

void HookMgr::FixAutoTradeName()
{
	PEHook::SETDWORD(0xE4 + 1, 0x0483C0C + 2);
	PEHook::SETDWORD(0xE4 + 1, 0x0483BF8 + 2);
	PEHook::SETDWORD(0xE4 + 1, 0x048544A + 2);
	PEHook::SETDWORD(0xE4 + 1, 0x0483EBE + 4);
}

void HookMgr::SetVersion(int version)
{
	PEHook::SETDWORD(version, 0x04864D2 + 6);
	PEHook::SETDWORD(version, 0x04B38BC + 6);
}

void HookMgr::SmallPatches()
{
	// Remove strdef checksum
	PEHook::SETBYTE(0xEB, 0x053A8D2);

}
bool HookMgr::InitializeConstants()
{
	try
	{

		HookMgr::ChangeWindowName();
		HookMgr::SmallPatches();
		HookMgr::FixAutoTradeName();
		HookMgr::SetVersion(778);
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

bool HookMgr::InitializeNakeds()
{
	try
	{
		PEHook::JMP_NEAR(0x0421356, Naked::NKD_ItemPrice_FormatDecimal);

		//Fix mage macro
		PEHook::JMP_NEAR(0x0497286, Naked::NKD_ChangeMacroRoute, 3);
		PEHook::JMP_NEAR(0x05165C5, Naked::NKD_MAutoAttackVerifyIsMage, 1);

		// Item Description Hook
		PEHook::JMP_NEAR(0x0419576, &Naked::NKD_ItemDescription, 4);

		// Fix macro mage
		PEHook::JE_NEAR(0x04974C7, &Naked::NKD_FixMageMacro);
		PEHook::JE_NEAR(0x04974D7, &Naked::NKD_FixMageMacro);

		// Add new commands
		PEHook::JMP_NEAR(0x04675F4, &Naked::NKD_NewCommands);

		// Minor hooks
		PEHook::JMP_NEAR(0x0417751, &Naked::NKD_ItemDesc_ChangePriceString_01, 1);
		PEHook::JMP_NEAR(0x041CDC7, &Naked::NKD_ItemDesc_ChangePriceString_02, 5);

		// Get packet class ptr
		PEHook::JMP_NEAR(0x0495AEE, &Naked::NKD_GetPacketClassPtr, 1);

		// Hook to intercept add/read message
		PEHook::JGE_NEAR(0x04252D6, &Naked::NKD_ReadMessage);

		PEHook::JMP_NEAR(0x0425887, &Naked::NKD_AddMessage, 2);

		/* Separar Item no Shift + Click*/
		PEHook::JMP_NEAR(0x4205FC, Naked::NKD_AddAmountItem, 4);


		// Fix Serverlist online users
		PEHook::FillWithNop(0x04B2D05, 8);
		PEHook::FillWithNop(0x046DDC6, 11);
		//teste height
		PEHook::FillWithNop(0x054DA76, 5);
		PEHook::SETBYTE( 0, 0x054DAE9 + 1);


		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}
