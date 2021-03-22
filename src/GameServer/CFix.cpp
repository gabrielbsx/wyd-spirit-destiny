#include "pch.h"
#include "CFix.h"

__declspec(naked) void CFix::NKD_FixClue_4()
{
	__asm
	{
		MOV ECX, DWORD PTR DS : [EAX + 0x7D852E8]
		CMP ECX, 0x0
		JE IsLeader
		MOV ECX, DWORD PTR DS : [EAX]
		IsLeader:
		PUSH 0x0584C18
		RETN
	}
}
