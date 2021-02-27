#include "pch.h"
#include "LuaGet.h"

void LuaGet::Initialize_MetaTable(lua_State* L)
{
	lua_newtable(L);
	int getTableID = lua_gettop(L);
	lua_pushvalue(L, getTableID);

	// atribui a variavel global
	lua_setglobal(L, "tGet");

#pragma region Exports Methods


#pragma endregion

	luaL_newmetatable(L, "GetMetaTable");

	lua_pushstring(L, "__index");
	lua_pushvalue(L, getTableID);
	lua_settable(L, -3);
}
