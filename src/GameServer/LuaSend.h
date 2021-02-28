#pragma once
#include <lua.hpp>
class LuaSend
{
public:
	static void Initialize_MetaTable(lua_State* L);
private:
	static int Lua_SendClientMessage(lua_State* L);
	static int Lua_SendHpMode(lua_State* L);
	static int Lua_SendAddParty(lua_State* L);
	static int Lua_SendCarry(lua_State* L);
	static int Lua_SendSetHpMp(lua_State* L);
	static int Lua_SendEmotion(lua_State* L);
	static int Lua_SendItem(lua_State* L);
	static int Lua_SendEquip(lua_State* L);
	static int Lua_SendShopList(lua_State* L);
	static int Lua_SendRandomQuiz(lua_State* L);
	static int Lua_SendEtc(lua_State* L);
	static int Lua_SendScore(lua_State* L);
	static int Lua_SendAffect(lua_State* L);
	static int Lua_SendSay(lua_State* L);
	static int Lua_SendNotice(lua_State* L);
	static int Lua_SendNoticeArea(lua_State* L);
	static int Lua_SendClientSignal(lua_State* L);
	static int Lua_SendClientSignalParm(lua_State* L);
	static int Lua_SendClientSignalParm2(lua_State* L);
	static int Lua_SendGridMob(lua_State* L);
	static int Lua_SendDoRecall(lua_State* L);
	static int Lua_SendCharLogOut(lua_State* L);
	static int Lua_SendPutItem(lua_State* L);
	static int Lua_SendRegenMob(lua_State* L);
	static int Lua_CloseUser(lua_State* L);
	static int Lua_SaveUser(lua_State* L);
	static int Lua_RemoveParty(lua_State* L);
	static int Lua_DoTeleport(lua_State* L);
	static int Lua_DoPartyTeleport(lua_State* L);
	static int Lua_CreateMob(lua_State* L);
	static int Lua_MountProcess(lua_State* L);
};