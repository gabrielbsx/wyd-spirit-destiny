#pragma once
#include "ILua.h"
#include <vector>

struct PacketHeader;

struct MSG_UseItem
{
	PacketHeader Header;
	int      SourType;
	int      SourPos;
	int      DestType;
	int      DestPos;

	unsigned short GridX, GridY;
	unsigned short WarpID;
};


enum class IType : int
{
	None = -1,
	Volatile,
	Index
};

class LuaVolatile :
	public ILua
{
public:

	LuaVolatile(IType Type, short RegisterID);
	~LuaVolatile();

	bool Execute(int clientId, int srcSlot, int srcType, int dstSlot, int dstType);

	static int lua_SendClientMessage(lua_State* L);
	/// TODO:
	/// static GetItemAmount
	/// static SetItemAmount
	/// static GetItemSanc
	/// static SetItemSanc
	/// static AmountMinus
	/// static PutItem
	/// static SendItem
	/// static SendClientMessage
	/// 

	
	static std::vector<LuaVolatile> Scripts;

	static bool LoadScripts();
	static void NKD_Modify();
	static bool OnExecute(int clientId, MSG_UseItem *pMsg);
	void RegisterFunctions();
public:
	IType myType;
	short myRegisterID;

};

