#include "pch.h"
#include "LuaPosition.h"

void LuaPosition::Initialize_MetaTable(lua_State* L)
{
	lua_newtable(L);
	int positionTableID = lua_gettop(L);
	lua_pushvalue(L, positionTableID);

	// atribui a variavel global
	lua_setglobal(L, "tPosition");

#pragma region Exports Methods


#pragma endregion

	luaL_newmetatable(L, "PositionMetaTable");

	lua_pushstring(L, "__index");
	lua_pushvalue(L, positionTableID);
	lua_settable(L, -3);
}
