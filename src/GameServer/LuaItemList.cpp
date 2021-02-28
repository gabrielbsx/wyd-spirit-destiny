#include "pch.h"
#include "LuaItemList.h"

void LuaItemList::Initialize_MetaTable(lua_State* L)
{
	lua_newtable(L);
	int itemTableID = lua_gettop(L);
	lua_pushvalue(L, itemTableID);

	// atribui a variavel global
	lua_setglobal(L, "tItemList");
#pragma region Exports functions

	lua_pushcfunction(L, Lua_CreateInstance); lua_setfield(L, -2, "new");
#pragma endregion

	luaL_newmetatable(L, "ItemListMetaTable");

	lua_pushstring(L, "__index");
	lua_pushvalue(L, itemTableID);
	lua_settable(L, -3);
}

int LuaItemList::Lua_CreateInstance(lua_State* L)
{
	void* item = lua_newuserdata(L, sizeof(STRUCT_ITEMLIST));

	new (item) STRUCT_ITEMLIST();

	short index = static_cast<short>(lua_tonumber(L, -2));
	if(index >= 0 && index < MAX_ITEMLIST)
	memcpy(item, &g_pItemList[index], sizeof(STRUCT_ITEMLIST));

	luaL_getmetatable(L, "ItemListMetaTable");
	assert(lua_istable(L, -1));
	lua_setmetatable(L, -2);
	return 1;
}