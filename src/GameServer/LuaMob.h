#pragma once
#include <lua.hpp>
class LuaMob
{
public:
	static void Initialize_MetaTable(lua_State* L);
private:
	static int Lua_StartMob(lua_State* L);
	static int Lua_FinishMob(lua_State* L);
	static int Lua_GetMobFace(lua_State* L);
};

