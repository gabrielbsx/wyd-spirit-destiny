#pragma once
#include <lua.hpp>
class LuaSend
{
public:
	static void Initialize_MetaTable(lua_State* L);
private:
	//Send.Message
	static int Lua_SendClientMessage(lua_State* L);
};

