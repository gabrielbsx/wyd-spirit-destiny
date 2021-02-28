#include "pch.h"
#include "LuaSend.h"
#include "Native.h"

void LuaSend::Initialize_MetaTable(lua_State* L)
{
	lua_newtable(L);
	int sendTableID = lua_gettop(L);
	lua_pushvalue(L, sendTableID);

	// atribui a variavel global
	lua_setglobal(L, "tSend");


	lua_pushcfunction(L, Lua_SendClientMessage);
	lua_setfield(L, -2, "Message");

	luaL_newmetatable(L, "SendMetaTable");

	lua_pushstring(L, "__index");
	lua_pushvalue(L, sendTableID);
	lua_settable(L, -3);
}

int LuaSend::Lua_SendClientMessage(lua_State* L)
{
	int connId = static_cast<int>(lua_tonumber(L, -2));
	auto message = lua_tostring(L, -1);

	if (connId <= 0 || connId >= MAX_USER)
		return 0;

	if (pUser[connId].Mode != USER_PLAY)
		return 0;

	if (strnlen_s(message, 96) >= 96)
		return 0;

	SendClientMessage(connId, message);
	return 0;
}

int LuaSend::Lua_SendHpMode(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendAddParty(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendCarry(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendSetHpMp(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendEmotion(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendItem(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendEquip(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendShopList(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendRandomQuiz(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendEtc(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendScore(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendAffect(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendSay(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendNotice(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendNoticeArea(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendClientSignal(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendClientSignalParm(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendClientSignalParm2(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendGridMob(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendDoRecall(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendCharLogOut(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendPutItem(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SendRegenMob(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_CloseUser(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_SaveUser(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_RemoveParty(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_DoTeleport(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_DoPartyTeleport(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_CreateMob(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_MountProcess(lua_State* L)
{
	return 0;
}

int LuaSend::Lua_DeliveryItemDrop(lua_State* L)
{
	return 0;
}
