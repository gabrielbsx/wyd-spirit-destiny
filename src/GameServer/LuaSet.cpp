#include "pch.h"
#include "LuaSet.h"

void LuaSet::Initialize_MetaTable(lua_State* L)
{
	lua_newtable(L);
	int sendTableID = lua_gettop(L);
	lua_pushvalue(L, sendTableID);

	// atribui a variavel global
	lua_setglobal(L, "tSet");
#pragma region Exports functions
	lua_pushcfunction(L, Lua_SetItemAmount); lua_setfield(L, -2, "SetItemAmount");
	lua_pushcfunction(L, Lua_SetItemSanc); lua_setfield(L, -2, "SetItemSanc");
	lua_pushcfunction(L, Lua_SetItemTime); lua_setfield(L, -2, "SetItemTime");
	lua_pushcfunction(L, Lua_SetQuestBit); lua_setfield(L, -2, "SetQuestBit");
	lua_pushcfunction(L, Lua_SetItemBonus); lua_setfield(L, -2, "SetItemBonus");
	lua_pushcfunction(L, Lua_SetCitizenship); lua_setfield(L, -2, "SetCitizenship");
	lua_pushcfunction(L, Lua_SetReqHp); lua_setfield(L, -2, "SetReqHp");
	lua_pushcfunction(L, Lua_SetReqMp); lua_setfield(L, -2, "SetReqMp");
	lua_pushcfunction(L, Lua_SetAffect); lua_setfield(L, -2, "SetAffect");
	lua_pushcfunction(L, Lua_SetKillCount); lua_setfield(L, -2, "SetKillCount");
	lua_pushcfunction(L, Lua_SetCP); lua_setfield(L, -2, "SetCP");
	lua_pushcfunction(L, Lua_SetQuestInfo); lua_setfield(L, -2, "SetQuestInfo");
	lua_pushcfunction(L, Lua_RemoveTrade); lua_setfield(L, -2, "RemoveTrade");
	lua_pushcfunction(L, Lua_RemoveAffect); lua_setfield(L, -2, "RemoveAffect");
	lua_pushcfunction(L, Lua_FinishCastleWar); lua_setfield(L, -2, "FinishCastleWar");
	lua_pushcfunction(L, Lua_GenerateMob); lua_setfield(L, -2, "GenerateMob");
	lua_pushcfunction(L, Lua_AddCrackError); lua_setfield(L, -2, "AddCrackError");
	lua_pushcfunction(L, Lua_ClearItem); lua_setfield(L, -2, "ClearItem");
	lua_pushcfunction(L, Lua_ClearItem); lua_setfield(L, -2, "ClearItem");
	lua_pushcfunction(L, Lua_AddGuildFame); lua_setfield(L, -2, "AddGuildFame");
	lua_pushcfunction(L, Lua_DeleteMob); lua_setfield(L, -2, "DeleteMob");
	lua_pushcfunction(L, Lua_DeleteGenerMob); lua_setfield(L, -2, "DeleteGenerMob");
	lua_pushcfunction(L, Lua_ClearArea); lua_setfield(L, -2, "ClearArea");
	lua_pushcfunction(L, Lua_ClearAreaLevel); lua_setfield(L, -2, "ClearAreaLevel");
	lua_pushcfunction(L, Lua_ClearAreaGuild); lua_setfield(L, -2, "ClearAreaGuild");
	lua_pushcfunction(L, Lua_ClearAreaTeleport); lua_setfield(L, -2, "ClearAreaTeleport");
	lua_pushcfunction(L, Lua_StartKephra); lua_setfield(L, -2, "StartKephra");
	lua_pushcfunction(L, Lua_AddTownTax); lua_setfield(L, -2, "AddTownTax");
	lua_pushcfunction(L, Lua_UpdateItem); lua_setfield(L, -2, "UpdateItem");
	lua_pushcfunction(L, Lua_Return); lua_setfield(L, -2, "Return");
	lua_pushcfunction(L, Lua_GenerateItem); lua_setfield(L, -2, "GenerateItem");
	lua_pushcfunction(L, Lua_SetLevel); lua_setfield(L, -2, "SetLevel");
#pragma endregion
	luaL_newmetatable(L, "SendMetaTable");

	lua_pushstring(L, "__index");
	lua_pushvalue(L, sendTableID);
	lua_settable(L, -3);
}

int LuaSet::Lua_SetItemAmount(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_SetItemSanc(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_SetItemTime(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_SetQuestBit(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_SetItemBonus(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_SetCitizenship(lua_State* L)
{
	return 0;
}

//sub_576960(signed int a1)
int LuaSet::Lua_SetReqHp(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_SetReqMp(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_SetAffect(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_SetKillCount(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_SetCP(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_SetQuestInfo(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_RemoveTrade(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_RemoveAffect(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_FinishCastleWar(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_GenerateMob(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_AddCrackError(lua_State* L)
{
	return 0;
}
//sub_4BE670(STRUCT_ITEM *a1)
int LuaSet::Lua_ClearItem(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_AddGuildFame(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_DeleteMob(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_DeleteGenerMob(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_ClearArea(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_ClearAreaLevel(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_ClearAreaGuild(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_ClearAreaTeleport(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_StartKephra(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_AddTownTax(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_UpdateItem(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_Return(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_GenerateItem(lua_State* L)
{
	return 0;
}

int LuaSet::Lua_SetLevel(lua_State* L)
{
	short conn = static_cast<short>(lua_tonumber(L, 1));
	short level = static_cast<short>(lua_tonumber(L, 2));
	pMob[conn].Mob.CurrentScore.Level = level;
	pMob[conn].Mob.BaseScore.Level = level;
	return 0;
}
