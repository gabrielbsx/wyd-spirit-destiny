#pragma once
#include <lua.hpp>
class LuaLog
{
public:
	static void Initialize_MetaTable(lua_State* L);
private:
	static int Lua_Log(lua_State* L);
};

