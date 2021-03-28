#include "pch.h"
#include "LuaExtra.h"
#include "CExtra.h"
#include "Native.h"
void LuaExtra::Initialize_MetaTable(lua_State* L)
{
	lua_newtable(L);
	int extraTableID = lua_gettop(L);
	lua_pushvalue(L, extraTableID);

	// atribui a variavel global
	lua_setglobal(L, "tExtra");

#pragma region Exports Methods

	lua_pushcfunction(L, Lua_CheckExtraQuest); lua_setfield(L, -2, "CheckQuest");
	lua_pushcfunction(L, Lua_SetExtraQuest); lua_setfield(L, -2, "SetQuest");
	lua_pushcfunction(L, Lua_ActiveAdmin); lua_setfield(L, -2, "SetAdmin");

#pragma endregion

	luaL_newmetatable(L, "ExtraMetaTable");

	lua_pushstring(L, "__index");
	lua_pushvalue(L, extraTableID);
	lua_settable(L, -3);
}

int LuaExtra::Lua_CheckExtraQuest(lua_State* L)
{
	auto position = static_cast<int>(lua_tonumber(L, -1));
	auto quest = static_cast<int>(lua_tonumber(L, -2));
	auto id = static_cast<int>(lua_tonumber(L, -3));

	if (id > 0 && id < MAX_USER)
	{
		if (pUser[id].Mode == USER_PLAY)
		{
			int maxQuest = ARRAYSIZE(g_pExtra[id].Account.QuestInfo.Quests);
			if (quest < 0 || quest >= maxQuest)
			{
				char szTmp[96]{ 0, };
				sprintf_s(szTmp, "!Utilize uma quest entre 0 - %d", maxQuest);
				SendClientMessage(id, szTmp);
				lua_pushboolean(L, false);
				return 1;
			}
			else
			{
				if (position < 0 || position >= 32)
				{
					SendClientMessage(id, "!Utilize uma posição entre 0 e 31");
					lua_pushboolean(L, false);
					return 1;
				}
				else
				{
					lua_pushboolean(L, !(g_pExtra[id].Account.QuestInfo.Quests[quest] & (1 << position)));
					return 1;
				}
			}
		}
	}
}


int LuaExtra::Lua_SetExtraQuest(lua_State* L)
{
	auto position = static_cast<int>(lua_tonumber(L, -1));
	auto quest = static_cast<int>(lua_tonumber(L, -2));
	auto id = static_cast<int>(lua_tonumber(L, -3));

	if (id > 0 && id < MAX_USER)
	{
		if (pUser[id].Mode == USER_PLAY)
		{
			int maxQuest = ARRAYSIZE(g_pExtra[id].Account.QuestInfo.Quests);
			if (quest < 0 || quest >= maxQuest)
			{
				char szTmp[96]{ 0, };
				sprintf_s(szTmp, "!SetExtra Quest precisa ser entre 0 - %d", maxQuest);
				SendClientMessage(id, szTmp);
				lua_pushboolean(L, false);
				return 1;
			}
			else
			{
				if (position < 0 || position >= 32)
				{
					SendClientMessage(id, "!SetExtra posição precisa ser entre 0 e 31");
					lua_pushboolean(L, false);
					return 1;
				}
				else
				{
					SaveUser(id);
					g_pExtra[id].Account.QuestInfo.Quests[quest] |= (1 << position);
					lua_pushboolean(L, (g_pExtra[id].Account.QuestInfo.Quests[quest] & (1 << position)));
					return 1;
				}
			}
		}
	}
}

int LuaExtra::Lua_ActiveAdmin(lua_State* L)
{
	auto id = static_cast<int>(lua_tonumber(L, -1));
	if (id > 0 && id < MAX_USER)
	{
		if (pUser[id].Mode == USER_PLAY)
		{
			if (g_pExtra[id].Account.Admin.AccessLevel > 0)
				g_pExtra[id].InGame.Admin.isAdmin = !g_pExtra[id].InGame.Admin.isAdmin;
		}
	}
	return 0;
}
