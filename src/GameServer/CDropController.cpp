#include "pch.h"
#include "CDropController.h"

std::vector<DROP_AREA> CDropController::vDropArea = std::vector<DROP_AREA>();
std::vector<short> CDropController::vBlockDrop = std::vector<short>();

__declspec(naked) void CDropController::NKD_BlockDrop()
{
	__asm
	{
		MOVSX ECX, WORD PTR DS : [EAX]
		PUSH ECX
		CALL CDropController::ProcessBlockDrop
		ADD ESP, 0x4
		CMP EAX, 0
		JE AbortExec
		PUSH 0x0571308
		RETN
		AbortExec:
		PUSH 0x0571319
		RETN
	}
}

__declspec(naked) void CDropController::NKD_DropArea()
{
	__asm
	{
		MOV EAX, DWORD PTR SS : [EBP - 0x95C]
		PUSH EAX
		MOV EAX, DWORD PTR SS : [EBP + 0x8]
		PUSH EAX
		CALL CDropController::DropMultiply
		ADD ESP, 0x8
		MOV DWORD PTR SS : [EBP - 0x95C] , EAX
		PUSH 0x05712BC
		RETN
	}
}
//5712FB
int CDropController::ProcessBlockDrop(short itemID)
{
	if (itemID <= 0)
		return false;


	return itemID;
}

int CDropController::DropMultiply(int conn, int rate)
{
	return rate;
}
