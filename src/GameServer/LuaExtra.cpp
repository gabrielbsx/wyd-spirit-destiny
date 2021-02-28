#include "pch.h"
#include "LuaExtra.h"
#include "CExtra.h"
void LuaExtra::Initialize_MetaTable(lua_State* L)
{
	lua_newtable(L);
	int extraTableID = lua_gettop(L);
	lua_pushvalue(L, extraTableID);

	// atribui a variavel global
	lua_setglobal(L, "tExtra");

#pragma region Exports Methods

	lua_pushcfunction(L, Lua_CreateInstance); lua_setfield(L, -2, "new");

#pragma endregion

	luaL_newmetatable(L, "ExtraMetaTable");

	lua_pushstring(L, "__index");
	lua_pushvalue(L, extraTableID);
	lua_settable(L, -3);
}

int LuaExtra::Lua_CreateInstance(lua_State* L)
{
	void* extra = lua_newuserdata(L, sizeof(CExtra));

	short index = static_cast<short>(lua_tonumber(L, -2));
	
	new (extra) CExtra();

	luaL_getmetatable(L, "ExtraMetaTable");

	assert(lua_istable(L, -1));

	lua_setmetatable(L, -2);

	return 1;
}
