#pragma once
#include <lua.hpp>
class LuaGet
{
public:
	static void Initialize_MetaTable(lua_State* L);
private:
	static int Lua_GetDistance(lua_State* L);
	static int Lua_GetItemAmount(lua_State* L);
	static int Lua_GetItemSanc(lua_State* L);
	static int Lua_GetItemAbility(lua_State* L);
	static int Lua_GetClan(lua_State* L);
	static int Lua_GetVillage(lua_State* L);
	static int Lua_GetAffect(lua_State* L);
	static int Lua_GetUserByName(lua_State* L);
	static int Lua_GetCP(lua_State* L);
	static int Lua_IsPlayerInArea(lua_State* L);
	static int Lua_IsJoinableItem(lua_State* L);
	static int Lua_CheckQuestBit(lua_State* L);
	static int Lua_Rand(lua_State* L);
};

