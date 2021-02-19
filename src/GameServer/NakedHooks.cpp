#include "pch.h"
#include "CHook.h"
#include <PEHook.h>
#include "DeactiveOriginals.h"
#include "PacketController.h"
bool CHook::SetNakeds()
{
	if (!DeactiveOriginals::Initialize())
		return false;

	PEHook::JMP_NEAR((DWORD)(BaseAddress + 0x068D90), PacketController::NKD_ModifyReceived, 4);
	PEHook::JMP_NEAR((DWORD)(BaseAddress + 0x026219), PacketController::NKD_ModifySended, 2);

	return true;
}
