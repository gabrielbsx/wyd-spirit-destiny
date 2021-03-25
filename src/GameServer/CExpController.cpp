#include "pch.h"
#include "CExpController.h"

//MOV DWORD PTR SS:[EBP-610],EAX parte 1
//MOV DWORD PTR SS:[EBP-60C],EDX parte 2 exp
//MOV EAX,DWORD PTR SS:[EBP+8] clientID
//56FA46
__declspec(naked) void CExpController::NKD_ExpMultiply()
{
	__asm
	{
		PUSH EDX
		PUSH EAX
		MOV ECX, DWORD PTR SS : [EBP + 0xC]
		PUSH ECX
		CALL CExpController::ProcessExpController
		ADD ESP, 0xC
		MOV DWORD PTR SS : [EBP - 0x610] , EAX
		MOV DWORD PTR SS : [EBP - 0x60C] , EDX
		PUSH 0x056FA52
		RETN
	}
}

INT64 CExpController::ProcessExpController(int conn, INT64 exp)
{
	return CExpController::ExpMultiply(conn, exp);
}

INT64 CExpController::ExpMultiply(int conn, INT64 exp)
{
	return exp;
}
