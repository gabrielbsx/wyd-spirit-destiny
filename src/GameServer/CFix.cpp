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

__declspec(naked) void CFix::NKD_GridMulticast_FixPosition()
{
	__asm
	{
		MOV EAX, DWORD PTR SS : [EBP + 0x10]
		SHL EAX, 0xD
		MOV ECX, DWORD PTR SS : [EBP + 0xC]

		PUSH 0x0503BEE
		RETN
	}
}
