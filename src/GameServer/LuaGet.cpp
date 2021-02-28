#include "pch.h"
#include "LuaGet.h"

void LuaGet::Initialize_MetaTable(lua_State* L)
{
	lua_newtable(L);
	int getTableID = lua_gettop(L);
	lua_pushvalue(L, getTableID);

	// atribui a variavel global
	lua_setglobal(L, "tGet");

#pragma region Exports Methods


#pragma endregion

	luaL_newmetatable(L, "GetMetaTable");

	lua_pushstring(L, "__index");
	lua_pushvalue(L, getTableID);
	lua_settable(L, -3);
}

int LuaGet::Lua_GetDistance(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_GetItemAmount(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_GetItemSanc(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_GetItemAbility(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_GetNewMantle(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_GetVillage(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_GetAffectSlotId(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_GetAction(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_GetCreateMob(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_GetCreateMob2(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_GetAffect(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_GetAttribute(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_GetCitizenship(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_GetUserByName(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_GetCP(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_IsPlayerInArea(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_CanCarry_7556(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_IsJoinableItem(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_CanCargo(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_CheckQuestBit(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_Rand(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_TMSRand(lua_State* L)
{
	return 0;
}

int LuaGet::Lua_CheckPremiumMount(lua_State* L)
{
	return 0;
}
