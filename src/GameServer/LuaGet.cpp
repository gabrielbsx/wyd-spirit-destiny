#include "pch.h"
#include "Native.h"
#include "LuaGet.h"

void LuaGet::Initialize_MetaTable(lua_State* L)
{
	lua_newtable(L);
	int getTableID = lua_gettop(L);
	lua_pushvalue(L, getTableID);

	// atribui a variavel global
	lua_setglobal(L, "tGet");

#pragma region Exports Methods
	lua_pushcfunction(L, Lua_GetDistance); lua_setfield(L, -2, "GetDistance");
	lua_pushcfunction(L, Lua_GetItemAmount); lua_setfield(L, -2, "GetItemAmount");
	lua_pushcfunction(L, Lua_GetItemSanc); lua_setfield(L, -2, "GetItemSanc");
	lua_pushcfunction(L, Lua_GetItemAbility); lua_setfield(L, -2, "GetItemAbility");
	lua_pushcfunction(L, Lua_GetNewMantle); lua_setfield(L, -2, "GetNewMantle");
	lua_pushcfunction(L, Lua_GetVillage); lua_setfield(L, -2, "GetVillage");
	lua_pushcfunction(L, Lua_GetAffectSlotId); lua_setfield(L, -2, "GetAffectSlotId");
	lua_pushcfunction(L, Lua_GetAction); lua_setfield(L, -2, "GetAction");
	lua_pushcfunction(L, Lua_GetCreateMob); lua_setfield(L, -2, "GetCreateMob");
	lua_pushcfunction(L, Lua_GetCreateMob2); lua_setfield(L, -2, "GetCreateMob2");
	lua_pushcfunction(L, Lua_GetAffect); lua_setfield(L, -2, "GetAffect");
	lua_pushcfunction(L, Lua_GetAttribute); lua_setfield(L, -2, "GetAttribute");
	lua_pushcfunction(L, Lua_GetUserByName); lua_setfield(L, -2, "GetUserByName");
	lua_pushcfunction(L, Lua_GetCP); lua_setfield(L, -2, "GetCP");
	lua_pushcfunction(L, Lua_IsPlayerInArea); lua_setfield(L, -2, "IsPlayerInArea");
	lua_pushcfunction(L, Lua_IsJoinableItem); lua_setfield(L, -2, "IsJoinableItem");
	lua_pushcfunction(L, Lua_CanCargo); lua_setfield(L, -2, "CanCargo");
	lua_pushcfunction(L, Lua_CheckQuestBit); lua_setfield(L, -2, "CheckQuestBit");
	lua_pushcfunction(L, Lua_Rand); lua_setfield(L, -2, "Rand");
	lua_pushcfunction(L, Lua_TMSRand); lua_setfield(L, -2, "TMSRand");
	lua_pushcfunction(L, Lua_CheckPremiumMount); lua_setfield(L, -2, "CheckPremiumMount");


#pragma endregion

	luaL_newmetatable(L, "GetMetaTable");

	lua_pushstring(L, "__index");
	lua_pushvalue(L, getTableID);
	lua_settable(L, -3);
}

int LuaGet::Lua_GetDistance(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_GetDistance");
	return 0;
}

int LuaGet::Lua_GetItemAmount(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_GetItemAmount");
	return 0;
}

int LuaGet::Lua_GetItemSanc(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_GetItemSanc");
	return 0;
}

int LuaGet::Lua_GetItemAbility(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_GetItemAbility");
	return 0;
}

int LuaGet::Lua_GetNewMantle(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_GetNewMantle");
	return 0;
}

int LuaGet::Lua_GetVillage(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_GetVillage");
	return 0;
}

int LuaGet::Lua_GetAffectSlotId(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_GetAffectSlotId");
	return 0;
}

int LuaGet::Lua_GetAction(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_GetAction");
	return 0;
}

int LuaGet::Lua_GetCreateMob(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_GetCreateMob");
	return 0;
}

int LuaGet::Lua_GetCreateMob2(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_GetCreateMob2");
	return 0;
}

int LuaGet::Lua_GetAffect(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_GetAffect");
	return 0;
}

int LuaGet::Lua_GetAttribute(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_GetAttribute");
	return 0;
}

int LuaGet::Lua_GetCitizenship(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_GetCitizenship");
	return 0;
}

int LuaGet::Lua_GetUserByName(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_GetUserByName");
	return 0;
}

int LuaGet::Lua_GetCP(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_GetCP");
	return 0;
}

int LuaGet::Lua_IsPlayerInArea(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_IsPlayerInArea");
	return 0;
}

int LuaGet::Lua_IsJoinableItem(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_IsJoinableItem");
	return 0;
}

int LuaGet::Lua_CanCargo(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_CanCargo");
	return 0;
}

int LuaGet::Lua_CheckQuestBit(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_CheckQuestBit");
	return 0;
}

int LuaGet::Lua_Rand(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_Rand");
	return 0;
}

int LuaGet::Lua_TMSRand(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_TMSRand");
	return 0;
}

int LuaGet::Lua_CheckPremiumMount(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_CheckPremiumMount");
	return 0;
}
