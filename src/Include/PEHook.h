// ---
// by ptr0x
// ---

#ifndef __PE_HOOK_H__
#define __PE_HOOK_H__

#include <windows.h>
#include <stdlib.h>
#include <cstdlib>

constexpr auto JE_NEAR_SIZE = 6;
constexpr auto JMP_NEAR_SIZE = 5;
constexpr auto JNZ_NEAR_SIZE = 6;
constexpr auto JGE_NEAR_SIZE = 6;
constexpr auto JLE_NEAR_SIZE = 6;
constexpr auto JG_NEAR_SIZE = 6;
constexpr int CALL_NEAR_SIZE = 5;

static DWORD dwOldProtect;

class PEHook
{
public:
	enum INSTRUCTIONS
	{
		JMP = 0xEB
	};

public:
	static void SETBYTE(BYTE value, DWORD dwAddress)
	{
		VirtualProtect((LPVOID)dwAddress, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &dwOldProtect);

		*(BYTE*)dwAddress = value;

		VirtualProtect((LPVOID)dwAddress, sizeof(BYTE), dwOldProtect, &dwOldProtect);
	}

	static void SETWORD(WORD value, DWORD dwAddress)
	{
		VirtualProtect((LPVOID)dwAddress, sizeof(WORD), PAGE_EXECUTE_READWRITE, &dwOldProtect);

		*(WORD*)dwAddress = value;

		VirtualProtect((LPVOID)dwAddress, sizeof(WORD), dwOldProtect, &dwOldProtect);
	}

	static void SETDWORD(DWORD value, DWORD dwAddress)
	{
		VirtualProtect((LPVOID)dwAddress, sizeof(DWORD), PAGE_EXECUTE_READWRITE, &dwOldProtect);

		*(DWORD*)dwAddress = value;

		VirtualProtect((LPVOID)dwAddress, sizeof(DWORD), dwOldProtect, &dwOldProtect);
	}

	static void SETFLOAT(float value, DWORD dwAddress)
	{
		VirtualProtect((LPVOID)dwAddress, sizeof(float), PAGE_EXECUTE_READWRITE, &dwOldProtect);

		*(float*)dwAddress = value;

		VirtualProtect((LPVOID)dwAddress, sizeof(float), dwOldProtect, &dwOldProtect);
	}

	static void SETDOUBLE(double value, DWORD dwAddress)
	{
		VirtualProtect((LPVOID)dwAddress, sizeof(float), PAGE_EXECUTE_READWRITE, &dwOldProtect);

		*(double*)dwAddress = value;

		VirtualProtect((LPVOID)dwAddress, sizeof(float), dwOldProtect, &dwOldProtect);
	}

	static void SETCALL(void* func, DWORD dwAddress)
	{
		VirtualProtect((LPVOID)dwAddress, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect);

		__asm
		{
			MOV EAX, func
			MOV ECX, dwAddress

			SUB EAX, ECX
			SUB EAX, 05h

			MOV DWORD PTR DS : [ECX] , 0E8h
			MOV DWORD PTR DS : [ECX + 1] , EAX
		}

		VirtualProtect((LPVOID)dwAddress, 5, dwOldProtect, &dwOldProtect);
	}

	static void DO_MEMCPY(void* dest, const void* src, DWORD size)
	{
		VirtualProtect(dest, size, PAGE_EXECUTE_READWRITE, &dwOldProtect);

		memcpy(dest, src, size);

		VirtualProtect(dest, size, dwOldProtect, &dwOldProtect);
	}

	static void BuildIndirection(DWORD dwAddress, BYTE* opCode, DWORD opCodeSize, void* dwFuncAddr)
	{
		DWORD
			dwInstructionSize = (opCodeSize + sizeof(DWORD)),
			dwDistance = (((DWORD)dwFuncAddr - dwAddress) - dwInstructionSize);

		BYTE
			* indirection = (BYTE*)malloc(opCodeSize + sizeof(DWORD));

		if (indirection == nullptr)
			return;

		// Build OpCode Instruction
		memcpy((BYTE*)&indirection[0], opCode, opCodeSize);

		// Build Distance of Instruction
		memcpy((BYTE*)&indirection[opCodeSize], &dwDistance, sizeof(DWORD));

		// Write Instruction
		VirtualProtect((LPVOID)dwAddress, dwInstructionSize, PAGE_EXECUTE_READWRITE, &dwOldProtect);

		memcpy((DWORD*)dwAddress, indirection, dwInstructionSize);

		free(indirection);

		VirtualProtect((LPVOID)dwAddress, dwInstructionSize, dwOldProtect, &dwOldProtect);
	}

	static void FillWithNop(DWORD dwAddress, DWORD dwSize)
	{
		BYTE
			* nop = (BYTE*)malloc(dwSize);

		if (nop == nullptr)
			return;

		VirtualProtect((LPVOID)dwAddress, dwSize, PAGE_EXECUTE_READWRITE, &dwOldProtect);

		for (DWORD i = 0; i < dwSize; i++)
			nop[i] = 0x90;

		memcpy((DWORD*)dwAddress, &nop[0], dwSize);

		free(nop);

		VirtualProtect((LPVOID)dwAddress, dwSize, dwOldProtect, &dwOldProtect);
	}

	static void JMP_NEAR(DWORD dwAddress, void* dwFuncAddr)
	{
		BYTE
			jmp = 0xE9;

		BuildIndirection(dwAddress, &jmp, 1, dwFuncAddr);
	}

	static void JMP_NEAR(DWORD dwAddress, void* dwFuncAddr, DWORD dwNopedSize)
	{
		JMP_NEAR(dwAddress, dwFuncAddr);

		FillWithNop(dwAddress + JMP_NEAR_SIZE, dwNopedSize);
	}

	static void JL_NEAR(DWORD dwAddress, void* dwFuncAddr)
	{
		BYTE
			jl[2] = { 0x0F, 0x8C };

		BuildIndirection(dwAddress, jl, 2, dwFuncAddr);
	}

	static void JLE_NEAR(DWORD dwAddress, void* dwFuncAddr)
	{
		BYTE
			jl[2] = { 0x0F, 0x8E };

		BuildIndirection(dwAddress, jl, 2, dwFuncAddr);
	}

	static void JLE_NEAR(DWORD dwAddress, void* dwFuncAddr, DWORD dwNopedSize)
	{
		JLE_NEAR(dwAddress, dwFuncAddr);

		FillWithNop(dwAddress + JLE_NEAR_SIZE, dwNopedSize);
	}

	static void JGE_NEAR(DWORD dwAddress, void* dwFuncAddr)
	{
		BYTE
			jge[2] = { 0x0F, 0x8D };

		BuildIndirection(dwAddress, jge, 2, dwFuncAddr);
	}

	static void JGE_NEAR(DWORD dwAddress, void* dwFuncAddr, DWORD dwNopedSize)
	{
		JGE_NEAR(dwAddress, dwFuncAddr);

		FillWithNop(dwAddress + JGE_NEAR_SIZE, dwNopedSize);
	}

	static void JG_NEAR(DWORD dwAddress, void* dwFuncAddr)
	{
		BYTE
			jg[2] = { 0x0F, 0x8F };

		BuildIndirection(dwAddress, jg, 2, dwFuncAddr);
	}

	static void JG_NEAR(DWORD dwAddress, void* dwFuncAddr, DWORD dwNopedSize)
	{
		JGE_NEAR(dwAddress, dwFuncAddr);

		FillWithNop(dwAddress + JG_NEAR_SIZE, dwNopedSize);
	}

	static void JNZ_NEAR(DWORD dwAddress, void* dwFuncAddr)
	{
		BYTE
			jnz[2] = { 0x0F, 0x85 };

		BuildIndirection(dwAddress, jnz, 2, dwFuncAddr);
	}

	static void JNZ_NEAR(DWORD dwAddress, void* dwFuncAddr, DWORD dwNopedSize)
	{
		JNZ_NEAR(dwAddress, dwFuncAddr);

		FillWithNop(dwAddress + JNZ_NEAR_SIZE, dwNopedSize);
	}

	static void JE_NEAR(DWORD dwAddress, void* dwFuncAddr)
	{
		BYTE
			je[2] = { 0x0F, 0x84 };

		BuildIndirection(dwAddress, je, 2, dwFuncAddr);
	}

	static void JE_NEAR(DWORD dwAddress, void* dwFuncAddr, DWORD dwNopedSize)
	{
		JE_NEAR(dwAddress, dwFuncAddr);

		FillWithNop(dwAddress + JE_NEAR_SIZE, dwNopedSize);
	}

	static void CALL_NEAR(DWORD dwAddress, void* dwFuncAddr)
	{
		BYTE
			call = 0xE8;

		BuildIndirection(dwAddress, &call, 1, dwFuncAddr);
	}

	static void CALL_NEAR(DWORD dwAddress, void* dwFuncAddr, DWORD dwNopedSize)
	{
		CALL_NEAR(dwAddress, dwFuncAddr);

		FillWithNop(dwAddress + CALL_NEAR_SIZE, dwNopedSize);
	}
};


#endif // __PE_HOOK_H__