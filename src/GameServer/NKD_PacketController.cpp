#include "pch.h"
#include "PacketController.h"


__declspec(naked) void PacketController::NKD_ModifyReceived()
{
	static DWORD lblContinueAddr = (DWORD)BaseAddress + 0x68D99;
	static DWORD lblExitAddr = (DWORD)BaseAddress + 0xA38F5;

	__asm
	{
		PUSH DWORD PTR SS : [EBP - 0xC] // buffer
		PUSH DWORD PTR SS : [EBP + 0x8] // USER
		CALL PacketController::ExecuteReceived
		ADD ESP, 0x8
		TEST AL, AL
		JE lblAbortExec
		MOV ECX, DWORD PTR SS : [EBP + 0x8]
		IMUL ECX, ECX, 0x0FC8

		MOV EAX, lblContinueAddr
		JMP EAX

		lblAbortExec :
		MOV EAX, lblExitAddr
			JMP EAX
	}
}

__declspec(naked) void PacketController::NKD_ModifySended()
{
	static DWORD pushAddr_A = (DWORD)BaseAddress + 0x26220;
	static DWORD pushAddr_B = (DWORD)BaseAddress + 0x26396;

	__asm
	{
		MOV ECX, DWORD PTR SS : [EBP + 0xC]
		PUSH ECX
		PUSH DWORD PTR SS : [EBP - 0x8]
		PUSH DWORD PTR SS : [EBP + 0x8]
		CALL PacketController::ExecuteSended
		ADD ESP, 0xC
		TEST AL, AL
		JE lblAbortExec

		MOV DWORD PTR SS : [EBP - 0x68] , 4

		PUSH pushAddr_A
		RETN

		lblAbortExec :
		PUSH pushAddr_B
			RETN
	}
}