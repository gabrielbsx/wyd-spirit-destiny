#pragma once
#include <lua.hpp>
class LuaUser
{
public:
	static void Initialize_MetaTable(lua_State* L);
private:
	static int Lua_StartUser(lua_State* L);
	static int Lua_GetState(lua_State* L);
};

