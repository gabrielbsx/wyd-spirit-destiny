#pragma once
#include <lua.hpp>
class LuaExtra
{
public:
	static void Initialize_MetaTable(lua_State* L);
private:
	static int Lua_CreateInstance(lua_State* L);
};

