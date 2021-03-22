#pragma once
#include <cstdarg>
#include <stdio.h>

constexpr auto COLORBASE = 0xFF000000;
enum ClientColor
{
	Black = COLORBASE + 0x000000,
	White = COLORBASE + 0xFFFFFF,
	Red = COLORBASE + 0xFF0000,
	Blue = COLORBASE + 0x0000FF,
	Yellow = COLORBASE + 0xFFFF00,
	LightGreen = COLORBASE + 0x00FF00
};

class scene_api
{
public:
	static int GetHud(int hudId)
	{
		int rtnValue = 0;
		__asm
		{
			PUSH hudId
			MOV EDX, DWORD PTR SS : [0x6F0AB0]
			MOV ECX, DWORD PTR DS : [EDX + 0x28]
			MOV EAX, DWORD PTR DS : [ECX]
			CALL DWORD PTR DS : [EAX + 0x48]

			MOV rtnValue, EAX
		}

		return rtnValue;
	}

	static void SetVisible(int hudId, int visible)
	{
		int handler = GetHud(hudId);

		if (handler == 0)
			return;

		__asm
		{
			PUSH visible
			MOV EAX, DWORD PTR DS : [handler]
			MOV EDX, DWORD PTR DS : [EAX]
			MOV ECX, DWORD PTR DS : [handler]
			CALL DWORD PTR DS : [EDX + 0x60]
		}
	}

	static void ChangeTextString(int hudId, const char* string)
	{
		int handler = GetHud(hudId);

		if (handler == 0)
			return;

		__asm
		{
			PUSH 0
			MOV EDX, string
			PUSH EDX

			MOV EAX, handler
			MOV EDX, DWORD PTR DS : [EAX]
			MOV ECX, handler
			CALL DWORD PTR DS : [EDX + 0x80]
		}
	}

	static void RefreshScene()
	{
		__asm
		{
			PUSH 0x0
			MOV ECX, DWORD PTR SS : [g_PacketClassPtr]

			MOV EAX, 0x04480C9
			CALL EAX
		}
	}

	static int CheckWindowState(int hudId)
	{
		int handler = GetHud(hudId);

		if (handler == 0)
			return -1;

		int retnValue = 0;

		__asm
		{
			MOV ECX, handler

			MOV EAX, 0x040C2C0
			CALL EAX

			MOV retnValue, EAX
		}

		return retnValue;
	}

	static void ConfirmMessage(int baseIdCode, const char* str_, const char* str2, ...)
	{
		char buff[1024];

		va_list arglist;
		va_start(arglist, str2);
		vsprintf(buff, str2, arglist);
		va_end(arglist);

		__asm
		{
			LEA EAX, DWORD PTR SS : [buff]
			PUSH EAX
			PUSH baseIdCode
			PUSH str_
			MOV EAX, DWORD PTR DS : [0x6F0AB0]
			MOV ECX, DWORD PTR DS : [EAX + 0xCC]
			MOV EDX, DWORD PTR DS : [0x6F0AB0]
			MOV EAX, DWORD PTR DS : [EDX + 0xCC]
			MOV EDX, DWORD PTR DS : [EAX]
			CALL DWORD PTR DS : [EDX + 0x8C]

			PUSH 0x1
			MOV EAX, DWORD PTR DS : [0x6F0AB0]
			MOV ECX, DWORD PTR DS : [EAX + 0xCC]
			MOV EDX, DWORD PTR DS : [0x6F0AB0]
			MOV EAX, DWORD PTR DS : [EDX + 0xCC]
			MOV EDX, DWORD PTR DS : [EAX]
			CALL DWORD PTR DS : [EDX + 0x60]
		}
	}

	static void AddLineToItem(int ebpValue, const char* text, int color = ClientColor::White)
	{
		int* ebp_28 = (int*)*(int*)(ebpValue - 0x28);
		int* ebp_10 = (int*)*(int*)(ebpValue - 0x10);
		int* ebp_18 = (int*)*(int*)(ebpValue - 0x18);

		__asm
		{
			MOV EAX, ebp_10
			MOV ECX, ebp_18
			MOV DWORD PTR DS : [EAX + 0x277CC] , ECX

			PUSH 0x0
			MOV EDX, text
			PUSH EDX

			MOV EAX, ebp_28
			MOV ECX, ebp_10
			MOV EDX, DWORD PTR DS : [ECX + EAX * 4 + 0x27A10]
			MOV EAX, ebp_28
			MOV ECX, ebp_10
			MOV ECX, DWORD PTR DS : [ECX + EAX * 4 + 0x27A10]
			MOV EDX, DWORD PTR DS : [EDX]
			MOV EAX, DWORD PTR DS : [EDX + 0x80]
			CALL EAX

			PUSH color
			MOV ECX, ebp_28
			MOV EDX, ebp_10
			MOV EAX, DWORD PTR DS : [EDX + ECX * 4 + 0x27A10]
			MOV ECX, ebp_28
			MOV EDX, ebp_10
			MOV ECX, DWORD PTR DS : [EDX + ECX * 4 + 0x27A10]
			MOV EAX, DWORD PTR DS : [EAX]
			MOV EDX, DWORD PTR DS : [EAX + 0x84]
			CALL EDX
		}

		int* increment = (int*)((int*)(ebpValue - 0x28));

		*increment += 1;
	}
};