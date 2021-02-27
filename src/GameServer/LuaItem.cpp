#include "pch.h"
#include "LuaItem.h"

void LuaItem::Initialize_MetaTable(lua_State* L)
{
	lua_newtable(L);
	int itemTableID = lua_gettop(L);
	lua_pushvalue(L, itemTableID);

	// atribui a variavel global
	lua_setglobal(L, "tItem");

#pragma region Exports Methods


#pragma endregion

	luaL_newmetatable(L, "ItemMetaTable");

	lua_pushstring(L, "__index");
	lua_pushvalue(L, itemTableID);
	lua_settable(L, -3);
}
