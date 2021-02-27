#include "pch.h"
#include "LuaUser.h"

void LuaUser::Initialize_MetaTable(lua_State* L)
{
	lua_newtable(L);
	int userTableID = lua_gettop(L);
	lua_pushvalue(L, userTableID);

	// atribui a variavel global
	lua_setglobal(L, "tUser");

#pragma region Exports Methods


#pragma endregion

	luaL_newmetatable(L, "UserMetaTable");

	lua_pushstring(L, "__index");
	lua_pushvalue(L, userTableID);
	lua_settable(L, -3);
}
