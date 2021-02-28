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
#pragma region Exports functions
	lua_pushcfunction(L, Lua_SendClientMessage); lua_setfield(L, -2, "SendClientMessage");
	lua_pushcfunction(L, Lua_SendHpMode); lua_setfield(L, -2, "SendHpMode");
	lua_pushcfunction(L, Lua_SendAddParty); lua_setfield(L, -2, "SendAddParty");
	lua_pushcfunction(L, Lua_SendCarry); lua_setfield(L, -2, "SendCarry");
	lua_pushcfunction(L, Lua_SendSetHpMp); lua_setfield(L, -2, "SendSetHpMp");
	lua_pushcfunction(L, Lua_SendEmotion); lua_setfield(L, -2, "SendEmotion");
	lua_pushcfunction(L, Lua_SendItem); lua_setfield(L, -2, "SendItem");
	lua_pushcfunction(L, Lua_SendEquip); lua_setfield(L, -2, "SendEquip");
	lua_pushcfunction(L, Lua_SendShopList); lua_setfield(L, -2, "SendShopList");
	lua_pushcfunction(L, Lua_SendRandomQuiz); lua_setfield(L, -2, "SendRandomQuiz");
	lua_pushcfunction(L, Lua_SendEtc); lua_setfield(L, -2, "SendEtc");
	lua_pushcfunction(L, Lua_SendScore); lua_setfield(L, -2, "SendScore");
	lua_pushcfunction(L, Lua_SendAffect); lua_setfield(L, -2, "SendAffect");
	lua_pushcfunction(L, Lua_SendSay); lua_setfield(L, -2, "SendSay");
	lua_pushcfunction(L, Lua_SendNotice); lua_setfield(L, -2, "SendNotice");
	lua_pushcfunction(L, Lua_SendNoticeArea); lua_setfield(L, -2, "SendNoticeArea");
	lua_pushcfunction(L, Lua_SendClientSignal); lua_setfield(L, -2, "SendClientSignal");
	lua_pushcfunction(L, Lua_SendClientSignalParm); lua_setfield(L, -2, "SendClientSignalParm");
	lua_pushcfunction(L, Lua_SendClientSignalParm2); lua_setfield(L, -2, "SendClientSignalParm2");
	lua_pushcfunction(L, Lua_SendGridMob); lua_setfield(L, -2, "SendGridMob");
	lua_pushcfunction(L, Lua_SendDoRecall); lua_setfield(L, -2, "SendDoRecall");
	lua_pushcfunction(L, Lua_SendCharLogOut); lua_setfield(L, -2, "SendCharLogOut");
	lua_pushcfunction(L, Lua_SendPutItem); lua_setfield(L, -2, "SendPutItem");
	lua_pushcfunction(L, Lua_SendRegenMob); lua_setfield(L, -2, "SendRegenMob");
	lua_pushcfunction(L, Lua_CloseUser); lua_setfield(L, -2, "SendCloseUser");
	lua_pushcfunction(L, Lua_SaveUser); lua_setfield(L, -2, "SendSaveUser");
	lua_pushcfunction(L, Lua_RemoveParty); lua_setfield(L, -2, "SendRemoveParty");
	lua_pushcfunction(L, Lua_DoTeleport); lua_setfield(L, -2, "SendTeleport");
	lua_pushcfunction(L, Lua_DoPartyTeleport); lua_setfield(L, -2, "SendPartyTeleport");
	lua_pushcfunction(L, Lua_CreateMob); lua_setfield(L, -2, "CreateMob");
	lua_pushcfunction(L, Lua_MountProcess); lua_setfield(L, -2, "SendMountProcess");
	lua_pushcfunction(L, Lua_MountProcess); lua_setfield(L, -2, "SendMountProcess");
#pragma endregion
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
	SendNotice("Not Implemented: tSend.Lua_SendHpMode");
	return 0;
}

int LuaSend::Lua_SendAddParty(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendAddParty");
	return 0;
}

int LuaSend::Lua_SendCarry(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendCarry");
	return 0;
}

int LuaSend::Lua_SendSetHpMp(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendSetHpMp");
	return 0;
}

int LuaSend::Lua_SendEmotion(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendEmotion");
	return 0;
}

int LuaSend::Lua_SendItem(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendItem");
	return 0;
}

int LuaSend::Lua_SendEquip(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendEquip");
	return 0;
}

int LuaSend::Lua_SendShopList(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendShopList");
	return 0;
}

int LuaSend::Lua_SendRandomQuiz(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendRandomQuiz");
	return 0;
}

int LuaSend::Lua_SendEtc(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendEtc");
	return 0;
}

int LuaSend::Lua_SendScore(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendScore");
	return 0;
}

int LuaSend::Lua_SendAffect(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendAffect");
	return 0;
}

int LuaSend::Lua_SendSay(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendSay");
	return 0;
}

int LuaSend::Lua_SendNotice(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendNotice");
	return 0;
}

int LuaSend::Lua_SendNoticeArea(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendNoticeArea");
	return 0;
}

int LuaSend::Lua_SendClientSignal(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendClientSignal");
	return 0;
}

int LuaSend::Lua_SendClientSignalParm(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendClientSignalParm");
	return 0;
}

int LuaSend::Lua_SendClientSignalParm2(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendClientSignalParm2");
	return 0;
}

int LuaSend::Lua_SendGridMob(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendGridMob");
	return 0;
}

int LuaSend::Lua_SendDoRecall(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendDoRecall");
	return 0;
}

int LuaSend::Lua_SendCharLogOut(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendCharLogOut");
	return 0;
}

int LuaSend::Lua_SendPutItem(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendPutItem");
	return 0;
}

int LuaSend::Lua_SendRegenMob(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SendRegenMob");
	return 0;
}

int LuaSend::Lua_CloseUser(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_CloseUser");
	return 0;
}

int LuaSend::Lua_SaveUser(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_SaveUser");
	return 0;
}

int LuaSend::Lua_RemoveParty(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_RemoveParty");
	return 0;
}

int LuaSend::Lua_DoTeleport(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_DoTeleport");
	return 0;
}

int LuaSend::Lua_DoPartyTeleport(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_DoPartyTeleport");
	return 0;
}

int LuaSend::Lua_CreateMob(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_CreateMob");
	return 0;
}

int LuaSend::Lua_MountProcess(lua_State* L)
{
	SendNotice("Not Implemented: tSend.Lua_MountProcess");
	return 0;
}