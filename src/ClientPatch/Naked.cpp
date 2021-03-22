#include "pch.h"
#include "Naked.h"
#include "Helper.h"

__declspec(naked) void Naked::NKD_ItemPrice_FormatDecimal()
{
	__asm
	{
		MOV EAX, DWORD PTR SS : [EBP - 08Ch]
		MOV ECX, DWORD PTR DS : [EAX + 058Ch]
		PUSH ECX

		MOV EAX, DWORD PTR SS : [EBP + 08h]
		PUSH EAX

		CALL Helper::ItemPrice_FormatDecimal_AutoTrade
		ADD ESP, 08h

		MOV EAX, 0x04213DA
		JMP EAX
	}
}

__declspec(naked) void Naked::NKD_ChangeMacroRoute()
{
	__asm
	{
		CMP DWORD PTR DS : [0x63A29C] , 2
		JE lbl_isMage
		JMP lbl_Continue

		lbl_isMage :
		MOV ECX, DWORD PTR SS : [EBP - 0x11C]
			CMP DWORD PTR DS : [ECX + 0x8A3A0] , 0x0
			JE lbl_isContinuos
			JMP lbl_Continue

			lbl_isContinuos :
		// Is mage macro, we send the mode as 2
		PUSH 2
			MOV EAX, DWORD PTR SS : [EBP - 0xC8]
			MOV EDX, 0x049728E
			JMP EDX

			lbl_Continue :
		PUSH 1
			MOV EAX, DWORD PTR SS : [EBP - 0xC8]
			MOV EDX, 0x049728E
			JMP EDX
	}
}

__declspec(naked) void Naked::NKD_MAutoAttackVerifyIsMage()
{
	__asm
	{
		CMP DWORD PTR SS : [EBP + 0xC] , 2
		JE lbl_goRoute
		MOV EDX, DWORD PTR SS : [EBP - 0x1C4]
		PUSH 0x05165CB
		RETN

		lbl_goRoute :
		PUSH 0x051701D
			RETN
	}
}

__declspec(naked) void Naked::NKD_ItemDescription()
{
	__asm
	{
		MOV ECX, DWORD PTR SS : [EBP - 0x8]
		MOV EDX, DWORD PTR DS : [ECX + 0x670]
		PUSH EDX
		PUSH EBP
		CALL Helper::ItemDescription

		MOV ECX, DWORD PTR SS : [EBP - 0x8]
		MOV EDX, DWORD PTR DS : [ECX + 0x670]
		PUSH 0x041957F
		RETN
	}
}

__declspec(naked) void Naked::NKD_VictoryCoupon_RequiredQuantity()
{
}

__declspec(naked) void Naked::NKD_FixMageMacro()
{
	__asm
	{
		MOV ECX, DWORD PTR SS : [EBP - 0x11C]
		// Diferente do Macro Continuo, então pula
		CMP DWORD PTR DS : [ECX + 0x8A3A0] , 0x0
		JNZ lbl_JMP
		PUSH 0x04970F9
		RETN

		lbl_JMP :
		PUSH 0x04972E5
			RETN
	}
}

__declspec(naked) void Naked::NKD_NewCommands()
{
	__asm
	{
		MOV EAX, DWORD PTR SS : [EBP - 0x98]
		MOV EDX, DWORD PTR DS : [EAX]
		MOV ECX, DWORD PTR SS : [EBP - 0x98]
		CALL DWORD PTR DS : [EDX + 0x88]
		PUSH EAX

		CALL Helper::NewCommands

		CMP AL, FALSE
		JE lbl_Continue
		PUSH 0x063A304
		MOV EAX, DWORD PTR SS : [EBP - 0x98]
		MOV EDX, DWORD PTR DS : [EAX]
		MOV ECX, DWORD PTR SS : [EBP - 0x98]
		CALL DWORD PTR DS : [EDX + 0x90]

		PUSH 0x0
		MOV EAX, DWORD PTR SS : [EBP - 0x2460]
		MOV ECX, DWORD PTR DS : [EAX + 0x28]
		MOV EDX, DWORD PTR SS : [EBP - 0x2460]
		MOV EAX, DWORD PTR DS : [EDX + 0x28]
		MOV EDX, DWORD PTR DS : [EAX]
		CALL DWORD PTR DS : [EDX + 0x40]
		MOV EAX, 1
		PUSH 0x0473794
		RETN

		lbl_Continue :
		PUSH 0x06140B0
			MOV EAX, 0x04675F9
			JMP EAX
	}
}

__declspec(naked) void Naked::NKD_ItemDesc_ChangePriceString_01()
{
	__asm
	{
		LEA EDX, DWORD PTR SS : [EBP - 0x33C]
		PUSH EDX

		MOV EAX, DWORD PTR SS : [EBP - 0x8]
		MOV ECX, DWORD PTR DS : [EAX + 0x670]

		PUSH ECX

		CALL Helper::ItemDesc_ChangePriceString

		CMP AL, FALSE
		JE lbl_normal
		PUSH 0x0417837
		RETN

		lbl_normal :
		MOV ECX, DWORD PTR SS : [EBP - 0x340]
			PUSH 0x0417757
			RETN
	}
}

__declspec(naked) void Naked::NKD_ItemDesc_ChangePriceString_02()
{
	__asm
	{
		LEA EDX, DWORD PTR SS : [EBP - 0x11D4]
		PUSH EDX

		MOV EAX, DWORD PTR SS : [EBP - 0x8]
		MOV ECX, DWORD PTR DS : [EAX + 0x670]

		PUSH ECX

		CALL Helper::ItemDesc_ChangePriceString

		CMP AL, FALSE
		JE lbl_normal
		MOV EAX, 0x041D05B
		JMP EAX

		lbl_normal :
		MOV EAX, DWORD PTR SS : [EBP - 0x10]
			CMP DWORD PTR DS : [EAX + 0x8C300] , 02h
			PUSH 0x041CDD1
			RETN
	}
}

__declspec(naked) void Naked::NKD_GetPacketClassPtr()
{
	__asm
	{
		MOV EAX, DWORD PTR SS : [EBP - 0xC]
		MOV DWORD PTR SS : [g_PacketClassPtr] , EAX

		MOV EDX, DWORD PTR SS : [EBP + 0xC]
		MOV DWORD PTR SS : [EBP - 0x4] , EDX

		MOV EAX, 0x0495AF4
		JMP EAX
	}
}

__declspec(naked) void Naked::NKD_ReadMessage()
{
	__asm
	{
		LEA ECX, DWORD PTR SS : [EBP - 0x8]
		PUSH ECX

		PUSH DWORD PTR SS : [EBP - 0x18]

		CALL Helper::ReadMessage

		PUSH 0x04253CC
		RETN
	}
}

__declspec(naked) void Naked::NKD_AddMessage()
{
	__asm
	{
		LEA ECX, DWORD PTR SS : [EBP - 0xC]
		PUSH ECX

		PUSH DWORD PTR SS : [EBP - 0x14]

		CALL Helper::AddMessage

		MOV DWORD PTR SS : [EBP - 0xC] , 0x4

		PUSH 0x042588E
		RETN
	}
}

__declspec(naked) void Naked::NKD_AddAmountItem()
{
	__asm
	{
		LEA ECX, DWORD PTR SS : [EBP - 0xC]
		PUSH ECX

		PUSH DWORD PTR SS : [EBP - 0x14]

		CALL Helper::AddMessage

		MOV DWORD PTR SS : [EBP - 0xC] , 0x4

		PUSH 0x042588E
		RETN
	}
}
