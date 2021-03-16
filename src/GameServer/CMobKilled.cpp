#include "pch.h"
#include "CMobKilled.h"

__declspec(naked) void CMobKilled::NKD_Modify()
{
	static DWORD firstPush = (DWORD)BaseAddress + 0xBE4DD;
	static DWORD secndPush = (DWORD)BaseAddress + 0xBE2B2;
	static DWORD thirdPush = (DWORD)BaseAddress + 0xBE2C2;

	__asm
	{
		PUSH DWORD PTR SS : [EBP + 0xC] // Killer
		PUSH DWORD PTR SS : [EBP + 0x8] // Killed
		PUSH DWORD PTR SS : [EBP - 0x5AC] // GenerateIndex
		CALL CMobKilled::Execute
		ADD ESP, 12

		TEST AL, AL // Se for false, vai pra próxima comparação
		JE lblContinueExec
		PUSH firstPush
		RETN

		lblContinueExec :
		CMP DWORD PTR SS : [EBP - 0x5AC] , 0x10E
			JL lblNext
			PUSH secndPush
			RETN

			lblNext :
		PUSH thirdPush
			RETN
	}

}

int CMobKilled::Execute(int killer, int killed, int posX, int posY)
{
	return true;
}
