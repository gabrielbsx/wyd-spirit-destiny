#include "pch.h"
#include "LuaItem.h"

void LuaItem::Initialize_MetaTable(lua_State* L)
{
	lua_newtable(L);
	int itemTableID = lua_gettop(L);
	lua_pushvalue(L, itemTableID);

	// atribui a variavel global
	lua_setglobal(L, "tItem");
#pragma region Exports functions

	lua_pushcfunction(L, Lua_CreateInstance); lua_setfield(L, -2, "new");
#pragma endregion

	luaL_newmetatable(L, "ItemMetaTable");

	lua_pushstring(L, "__index");
	lua_pushvalue(L, itemTableID);
	lua_settable(L, -3);
}

int LuaItem::Lua_CreateInstance(lua_State* L)
{
	void* item = lua_newuserdata(L, sizeof(STRUCT_ITEM));

	short index = static_cast<short>(lua_tonumber(L, -8));// 2, 3, 4, 5, 6, 7, 8
	BYTE EF1 = static_cast<BYTE>(lua_tonumber(L, -7));// 2, 3, 4, 5, 6, 7, 8
	BYTE EFV1 = static_cast<BYTE>(lua_tonumber(L, -6));// 2, 3, 4, 5, 6, 7, 8
	BYTE EF2 = static_cast<BYTE>(lua_tonumber(L, -5));// 2, 3, 4, 5, 6, 7, 8
	BYTE EFV2 = static_cast<BYTE>(lua_tonumber(L, -4));// 2, 3, 4, 5, 6, 7, 8
	BYTE EF3 = static_cast<BYTE>(lua_tonumber(L, -3));// 2, 3, 4, 5, 6, 7, 8
	BYTE EFV3 = static_cast<BYTE>(lua_tonumber(L, -2));// 2, 3, 4, 5, 6, 7, 8

	new (item) STRUCT_ITEM(index, EF1, EFV1, EF2, EFV2, EF3, EFV3);

	


	luaL_getmetatable(L, "ItemMetaTable");

	assert(lua_istable(L, -1));

	lua_setmetatable(L, -2);

	return 1;
}
