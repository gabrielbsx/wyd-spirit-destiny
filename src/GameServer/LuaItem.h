#pragma once
#include <lua.hpp>
class LuaItem
{
public:
	static void Initialize_MetaTable(lua_State* L);
private:
	static int Lua_CreateInstance(lua_State* L);
	static int Lua_SetValues(lua_State* L);
	static int Lua_FinishItem(lua_State* L);
};

