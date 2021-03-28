#pragma once
#include <lua.hpp>
class LuaExtra
{
public:
	static void Initialize_MetaTable(lua_State* L);
private:
	static int Lua_CheckExtraQuest(lua_State* L);
	static int Lua_SetExtraQuest(lua_State* L);
	static int Lua_ActiveAdmin(lua_State* L);
};

