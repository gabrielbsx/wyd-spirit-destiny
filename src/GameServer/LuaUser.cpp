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

	lua_pushcfunction(L, Lua_StartUser);
	lua_setfield(L, -2, "new");

	lua_pushcfunction(L, Lua_GetState);
	lua_setfield(L, -2, "GetState");

#pragma endregion

	luaL_newmetatable(L, "UserMetaTable");

	lua_pushstring(L, "__index");
	lua_pushvalue(L, userTableID);
	lua_settable(L, -3);
}

int LuaUser::Lua_StartUser(lua_State* L)
{
	void* mob = lua_newuserdata(L, sizeof(CUser));
	new (mob) CUser();
	int index = static_cast<int>(lua_tonumber(L, -2));
	memcpy(mob, &pUser[index], sizeof(CUser));
	luaL_getmetatable(L, "UserMetaTable");
	assert(lua_istable(L, -1));
	lua_setmetatable(L, -2);
	return 1;
}

int LuaUser::Lua_GetState(lua_State* L)
{
	CUser* user = (CUser*)lua_touserdata(L, -1);
	lua_pushnumber(L, user->Mode);
	return 1;
}
