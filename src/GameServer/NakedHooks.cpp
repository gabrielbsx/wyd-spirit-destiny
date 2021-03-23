#include "pch.h"
#include "CHook.h"
#include <PEHook.h>
#include "DeactiveOriginals.h"
#include "PacketController.h"
#include "CMobKilled.h"
#include "CFix.h"
bool CHook::SetNakeds()
{
	if (!DeactiveOriginals::Initialize())
		return false;

	PEHook::JMP_NEAR((DWORD)(BaseAddress + 0x068D90), PacketController::NKD_ModifyReceived, 4);
	PEHook::JMP_NEAR((DWORD)(BaseAddress + 0x026219), PacketController::NKD_ModifySended, 2);
	PEHook::JMP_NEAR((DWORD)(BaseAddress + 0x0BE2A2), CMobKilled::NKD_Modify, 5);

	//Fix Pista +4
	PEHook::JMP_NEAR((DWORD)(BaseAddress + 0x0D3C12), CFix::NKD_FixClue_4, 1);
	//Fix pista +5
	PEHook::SETBYTE(0x0, ((DWORD)(BaseAddress + 0xD421B)));

	// Fix grid error
	PEHook::JMP_NEAR(0x503BDD, CFix::NKD_GridMulticast_FixPosition, 1);

	return true;
}
