#include "pch.h"
#include "LuaSend.h"
#include "Native.h"

void LuaSend::Initialize_MetaTable(lua_State* L)
{
	lua_newtable(L);
	int sendTableID = lua_gettop(L);
	lua_pushvalue(L, sendTableID);

	lua_setglobal(L, "tSend");
#pragma region Exports functions
	lua_pushcfunction(L, Lua_SendClientMessage); lua_setfield(L, -2, "SendClientMessage");
	lua_pushcfunction(L, Lua_SendEmotion); lua_setfield(L, -2, "SendEmotion");
	lua_pushcfunction(L, Lua_SendItem); lua_setfield(L, -2, "SendItem");
	lua_pushcfunction(L, Lua_SendEquip); lua_setfield(L, -2, "SendEquip");
	lua_pushcfunction(L, Lua_SendEtc); lua_setfield(L, -2, "SendEtc");
	lua_pushcfunction(L, Lua_SendScore); lua_setfield(L, -2, "SendScore");
	lua_pushcfunction(L, Lua_SendAffect); lua_setfield(L, -2, "SendAffect");
	lua_pushcfunction(L, Lua_SendSay); lua_setfield(L, -2, "SendSay");
	lua_pushcfunction(L, Lua_SendNotice); lua_setfield(L, -2, "SendNotice");
	lua_pushcfunction(L, Lua_SendDoRecall); lua_setfield(L, -2, "SendDoRecall");
	lua_pushcfunction(L, Lua_SendCharLogOut); lua_setfield(L, -2, "SendCharLogOut");
	lua_pushcfunction(L, Lua_SendPutItem); lua_setfield(L, -2, "SendPutItem");
	lua_pushcfunction(L, Lua_CloseUser); lua_setfield(L, -2, "SendCloseUser");
	lua_pushcfunction(L, Lua_SaveUser); lua_setfield(L, -2, "SendSaveUser");
	lua_pushcfunction(L, Lua_DoTeleport); lua_setfield(L, -2, "SendTeleport");
	lua_pushcfunction(L, Lua_SetAffect); lua_setfield(L, -2, "SetAffect");
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

int LuaSend::Lua_SendEmotion(lua_State* L)
{
	auto conn = static_cast<int>(lua_tonumber(L, -3));
	short param1 = static_cast<short>(lua_tonumber(L, -2));
	short param2 = static_cast<short>(lua_tonumber(L, -1));
	auto resEmotion = SendEmotion(conn, param1, param2);
	lua_pushnumber(L, resEmotion);
	return 1;
}

int LuaSend::Lua_SendItem(lua_State* L)
{
	auto item = (STRUCT_ITEM*)lua_touserdata(L, -1);
	short slot = static_cast<short>(lua_tonumber(L, -2));
	short type = static_cast<short>(lua_tonumber(L, -3));
	short conn = static_cast<int>(lua_tonumber(L, -4));
	
	SendItem(conn, type, slot, item);
	return 0;
}

int LuaSend::Lua_SendEquip(lua_State* L)
{
	short type = static_cast<int>(lua_tonumber(L, -1));
	int conn = static_cast<int>(lua_tonumber(L, -2));
	auto resEquip = SendEquip(conn, type);
	lua_pushnumber(L, resEquip);
	return 1;
}

int LuaSend::Lua_SendEtc(lua_State* L)
{
	int conn = static_cast<int>(lua_tonumber(L, -1));
	SendEtc(conn);
	return 0;
}

int LuaSend::Lua_SendScore(lua_State* L)
{

	int conn = static_cast<int>(lua_tonumber(L, -1));
	GetCurrentScore(conn);
	SendScore(conn);
	return 0;
}

int LuaSend::Lua_SendAffect(lua_State* L)
{
	int conn = static_cast<int>(lua_tonumber(L, -1));
	SendAffect(conn);
	return 0;
}

int LuaSend::Lua_SetAffect(lua_State* L)
{
	int conn = static_cast<int>(lua_tonumber(L, -4));
	int Affect = static_cast<int>(lua_tonumber(L, -3));
	int Time = static_cast<int>(lua_tonumber(L, -2));
	int Value = static_cast<int>(lua_tonumber(L, -1));
	SetAffect(conn, Affect, Time, Value);
	return 0;
}

int LuaSend::Lua_SendSay(lua_State* L)
{
	int conn = static_cast<int>(lua_tonumber(L, -2));
	auto say = lua_tostring(L, -1);
	SendSay(conn, say);
	return 0;
}

int LuaSend::Lua_SendNotice(lua_State* L)
{

	auto notc = lua_tostring(L, -1);
	SendNotice(notc);
	return 0;
}

int LuaSend::Lua_SendDoRecall(lua_State* L)
{
	int conn = static_cast<int>(lua_tonumber(L, -1));
	DoRecall(conn);
	return 0;
}

int LuaSend::Lua_SendCharLogOut(lua_State* L)
{
	int conn = static_cast<int>(lua_tonumber(L, -1));
	CharLogout(conn);
	return 0;
}

int LuaSend::Lua_SendPutItem(lua_State* L)
{
	auto item = (STRUCT_ITEM*)lua_touserdata(L, -1);

	int conn = static_cast<int>(lua_tonumber(L, -2));
	PutItem(conn, item);
	return 0;
}

int LuaSend::Lua_CloseUser(lua_State* L)
{
	int conn = static_cast<int>(lua_tonumber(L, -1));
	CloseUser(conn);
	return 0;
}

int LuaSend::Lua_SaveUser(lua_State* L)
{

	int conn = static_cast<int>(lua_tonumber(L, -1));
	SaveUser(conn);
	return 0;
}

int LuaSend::Lua_DoTeleport(lua_State* L)
{
	int conn = static_cast<int>(lua_tonumber(L, -3));
	int posX = static_cast<int>(lua_tonumber(L, -2));
	int posY = static_cast<int>(lua_tonumber(L, -1));
	DoTeleport(conn, posX, posY, 0);
	return 0;
}