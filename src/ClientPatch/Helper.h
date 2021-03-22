#pragma once

enum e_hooksState {
	Recv_Hook,
	Send_Hook
};




class Helper
{
public:
	static void ItemPrice_FormatDecimal_AutoTrade(char* gold, int value);
	static void __stdcall ItemDescription(int ebp, st_Item* item);
	static bool __stdcall NewCommands(char* command);
	static bool __stdcall ItemDesc_ChangePriceString(st_Item* item, char* text);
	static void __stdcall AddMessage(char* msg, int* size);
	static void __stdcall ReadMessage(char* msg, int* size);
};

