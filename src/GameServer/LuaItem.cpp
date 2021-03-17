#include "pch.h"
#include "LuaItem.h"

void LuaItem::Initialize_MetaTable(lua_State* L)
{
	lua_newtable(L);
	int itemTableID = lua_gettop(L);
	lua_pushvalue(L, itemTableID);

	// atribui a variavel global
	lua_setglobal(L, "CItem");
#pragma region Exports functions

	lua_pushcfunction(L, Lua_CreateInstance); lua_setfield(L, -2, "new");
	lua_pushcfunction(L, Lua_SetValues); lua_setfield(L, -2, "SetValue");
#pragma endregion

	luaL_newmetatable(L, "ItemMetaTable");


	lua_pushstring(L, "__gc");
	lua_pushcfunction(L, Lua_FinishItem);

	lua_settable(L, -3);
	lua_pushstring(L, "__index");
	lua_pushvalue(L, itemTableID);
	lua_settable(L, -3);
}

int LuaItem::Lua_CreateInstance(lua_State* L)
{
	void* item = lua_newuserdata(L, sizeof(STRUCT_ITEM));
	short index = 0;
	BYTE EF1 = 0, EFV1 = 0, EF2 = 0, EFV2 = 0, EF3 = 0, EFV3 = 0;

	new (item) STRUCT_ITEM(index, EF1, EFV1, EF2, EFV2, EF3, EFV3);

	luaL_getmetatable(L, "ItemMetaTable");

	assert(lua_istable(L, -1));

	lua_setmetatable(L, -2);

	return 1;
}

int LuaItem::Lua_SetValues(lua_State* L)
{
	STRUCT_ITEM* mtItem = (STRUCT_ITEM*)lua_touserdata(L, 1);
	short index = 0;
	BYTE EF1 = 0, EFV1 = 0, EF2 = 0, EFV2 = 0, EF3 = 0, EFV3 = 0;
	if (lua_isnumber(L, 2))
		index = static_cast<short>(lua_tonumber(L, 2));
	if (lua_isnumber(L, 3))
		EF1 = static_cast<BYTE>(lua_tonumber(L, 3));
	if (lua_isnumber(L, 4))
		EFV1 = static_cast<BYTE>(lua_tonumber(L, 4));
	if (lua_isnumber(L, 5))
		EF2 = static_cast<BYTE>(lua_tonumber(L, 5));
	if (lua_isnumber(L, 6))
		EFV2 = static_cast<BYTE>(lua_tonumber(L, 6));
	if (lua_isnumber(L, 7))
		EF3 = static_cast<BYTE>(lua_tonumber(L, 7));
	if (lua_isnumber(L, 8))
		EFV3 = static_cast<BYTE>(lua_tonumber(L, 8));
		
	mtItem->sIndex = index;
	mtItem->stEffect[0].cEffect = EF1; mtItem->stEffect[0].cValue = EFV1;
	mtItem->stEffect[1].cEffect = EF2; mtItem->stEffect[1].cValue = EFV2;
	mtItem->stEffect[2].cEffect = EF3; mtItem->stEffect[2].cValue = EFV3;
	return 0;
}

int LuaItem::Lua_FinishItem(lua_State* L)
{
	STRUCT_ITEM* item = (STRUCT_ITEM*)lua_touserdata(L, -1);
	delete[] item;
	return 0;
}
