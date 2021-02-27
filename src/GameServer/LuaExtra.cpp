#include "pch.h"
#include "LuaExtra.h"

void LuaExtra::Initialize_MetaTable(lua_State* L)
{
	lua_newtable(L);
	int extraTableID = lua_gettop(L);
	lua_pushvalue(L, extraTableID);

	// atribui a variavel global
	lua_setglobal(L, "tExtra");

#pragma region Exports Methods


#pragma endregion

	luaL_newmetatable(L, "ExtraMetaTable");

	lua_pushstring(L, "__index");
	lua_pushvalue(L, extraTableID);
	lua_settable(L, -3);
}
