#pragma once
#include <lua.hpp>
class LuaSet
{
public:
	static void Initialize_MetaTable(lua_State* L);
private:
	static int Lua_SetItemAmount(lua_State* L);
	static int Lua_SetItemSanc(lua_State* L);
	static int Lua_SetItemTime(lua_State* L);
	static int Lua_SetQuestBit(lua_State* L);
	static int Lua_SetItemBonus(lua_State* L);
	static int Lua_SetCitizenship(lua_State* L);
	static int Lua_SetReqHp(lua_State* L);
	static int Lua_SetReqMp(lua_State* L);
	static int Lua_SetAffect(lua_State* L);
	static int Lua_SetKillCount(lua_State* L);
	static int Lua_SetCP(lua_State* L);
	static int Lua_SetQuestInfo(lua_State* L);
	static int Lua_RemoveTrade(lua_State* L);
	static int Lua_RemoveAffect(lua_State* L);
	static int Lua_FinishCastleWar(lua_State* L);
	static int Lua_GenerateMob(lua_State* L);
	static int Lua_AddCrackError(lua_State* L);
	static int Lua_ClearItem(lua_State* L);
	static int Lua_AddGuildFame(lua_State* L);
	static int Lua_DeleteMob(lua_State* L);
	static int Lua_DeleteGenerMob(lua_State* L);
	static int Lua_ClearArea(lua_State* L);
	static int Lua_ClearAreaLevel(lua_State* L);
	static int Lua_ClearAreaGuild(lua_State* L);
	static int Lua_ClearAreaTeleport(lua_State* L);
	static int Lua_StartKephra(lua_State* L);
	static int Lua_AddTownTax(lua_State* L);
	static int Lua_UpdateItem(lua_State* L);
	static int Lua_Return(lua_State* L);
	static int Lua_GenerateItem(lua_State* L);
};