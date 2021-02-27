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
