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
	lua_pushcfunction(L, Lua_GetClan); lua_setfield(L, -2, "GetClan");
	lua_pushcfunction(L, Lua_GetVillage); lua_setfield(L, -2, "GetVillage");
	lua_pushcfunction(L, Lua_GetAffect); lua_setfield(L, -2, "GetAffect");
	lua_pushcfunction(L, Lua_GetUserByName); lua_setfield(L, -2, "GetIndexByName");
	lua_pushcfunction(L, Lua_GetCP); lua_setfield(L, -2, "GetCP");
	lua_pushcfunction(L, Lua_IsPlayerInArea); lua_setfield(L, -2, "IsPlayerInArea");
	lua_pushcfunction(L, Lua_IsJoinableItem); lua_setfield(L, -2, "IsJoinableItem");
	lua_pushcfunction(L, Lua_CheckQuestBit); lua_setfield(L, -2, "CheckQuestBit");
	lua_pushcfunction(L, Lua_Rand); lua_setfield(L, -2, "Rand");
#pragma endregion

	luaL_newmetatable(L, "GetMetaTable");

	lua_pushstring(L, "__index");
	lua_pushvalue(L, getTableID);
	lua_settable(L, -3);
}

int LuaGet::Lua_GetDistance(lua_State* L)
{
	// testar depois
	auto y2 = static_cast<short>(lua_tonumber(L, -4));
	auto x2 = static_cast<short>(lua_tonumber(L, -3));
	auto y1 = static_cast<short>(lua_tonumber(L, -2));
	auto x1 = static_cast<short>(lua_tonumber(L, -1));
	auto dist = BASE_GetDistance(x1, y1, x2, y2);
	lua_pushnumber(L, dist);
	return 1;
}

int LuaGet::Lua_GetItemAmount(lua_State* L)
{
	// testar depois
	STRUCT_ITEM* item = (STRUCT_ITEM*)lua_touserdata(L, -1);
	int amount = BASE_GetItemAmount(item);
	lua_pushnumber(L, amount);
	return 1;
}

int LuaGet::Lua_GetItemSanc(lua_State* L)
{
	STRUCT_ITEM* item = (STRUCT_ITEM*)lua_touserdata(L, -1);
	int sanc = BASE_GetItemSanc(item);
	lua_pushnumber(L, sanc);
	return 1;
}

int LuaGet::Lua_GetItemAbility(lua_State* L)
{
	STRUCT_ITEM* item = (STRUCT_ITEM*)lua_touserdata(L, -2);
	auto eff = static_cast<unsigned char>(lua_tonumber(L, -1));
	int hab = BASE_GetItemAbility(item, eff);
	lua_pushnumber(L, hab);
	return 1;
}

int LuaGet::Lua_GetClan(lua_State* L)
{
	auto id = static_cast<int>(lua_tonumber(L, -1));
	int clan = BASE_GetClan(pMob[id].Mob.Equip[15].sIndex);
	lua_pushnumber(L, clan);
	return 1;
}

int LuaGet::Lua_GetVillage(lua_State* L)
{
	auto x = static_cast<int>(lua_tonumber(L, -2));
	auto y = static_cast<int>(lua_tonumber(L, -1));
	auto village = BASE_GetVillage(x, y);
	lua_pushnumber(L, village);
	return 1;
}

int LuaGet::Lua_GetAffect(lua_State* L)
{
	auto mobID = static_cast<int>(lua_tonumber(L, -2));
	auto AffectID = static_cast<int>(lua_tonumber(L, -1));
	for (int i = 0; i < ARRAYSIZE(pMob[mobID].Affects); i++)
	{
		if (pMob[mobID].Affects[i].Type == AffectID)
		{
			lua_pushnumber(L, i);
			return 1;
		}
	}
	lua_pushnumber(L, -1);
	return 1;
}

int LuaGet::Lua_GetUserByName(lua_State* L)
{
	auto mobID = lua_tostring(L, -1);
	for (int i = 0; i < MAX_USER; i++)
	{
		if (!strncmp(pMob[i].Mob.MobName, mobID, 16))
		{
			lua_pushnumber(L, i);
			return 1;
		}
	}
	lua_pushnumber(L, -1);
	return 1;
}

int LuaGet::Lua_GetCP(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_GetCP");
	return 0;
}

int LuaGet::Lua_IsPlayerInArea(lua_State* L)
{
	auto mobID = static_cast<int>(lua_tonumber(L, -5));
	auto xMin = static_cast<int>(lua_tonumber(L, -4));
	auto yMin = static_cast<int>(lua_tonumber(L, -3));
	auto xMax = static_cast<int>(lua_tonumber(L, -2));
	auto yMax = static_cast<int>(lua_tonumber(L, -1));

	auto posX = pMob[mobID].PosX;
	auto posY = pMob[mobID].PosY;
	if (posX >= xMin && posY >= yMin && posX <= xMax && posY <= yMax)
	{
		lua_pushboolean(L, true);
		return 1;
	}
	lua_pushboolean(L, false);
	return 1;
}

int LuaGet::Lua_IsJoinableItem(lua_State* L)
{
	SendNotice("Not Implemented: tGet.Lua_IsJoinableItem");
	return 0;
}

int LuaGet::Lua_CheckQuestBit(lua_State* L)
{
	auto quest = static_cast<char>(lua_tonumber(L, -2));
	auto id = static_cast<int>(lua_tonumber(L, -1));
	auto questflag = BASE_CheckQuestBit(quest, id);
	lua_pushboolean(L, questflag);
	return 1;
}

int LuaGet::Lua_Rand(lua_State* L)
{
	auto max_rnd = static_cast<int>(lua_tonumber(L, -1));
	int rnd = rand() % max_rnd;
	lua_pushinteger(L, rnd);
	return 1;
}

