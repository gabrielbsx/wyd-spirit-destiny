#pragma once
#include <lua.hpp>
#include <string>
//class CUser;
//class CMob;
//class CExtra;
class ILua
{
private:
	lua_State* L = nullptr;
	std::string MethodName;
	int NumArgs;
	int NumReturns;
public:
	ILua(std::string nMethod, int nArgs, int nReturn = 0)
	{
		this->L = luaL_newstate();
		this->MethodName = nMethod;
		this->NumArgs = nArgs;
		this->NumReturns = nReturn;
	};
	~ILua()
	{
	};
	bool LoadScript(std::string fileName)
	{
		auto result = luaL_dofile(this->L, fileName.c_str());
		if (result == LUA_OK)
			return true;

		lua_close(L);
		return false;
	}

	std::string GetMethodName()
	{
		return this->MethodName;
	}
	lua_State* GetLuaState()
	{
		return this->L;
	}
	int GetNumArgs()
	{
		return this->NumArgs;
	}
	int GetNumReturn()
	{
		return this->NumReturns;
	}
	inline static bool GetBoolean(lua_State* L, int arg)
	{
		return static_cast<bool>(lua_toboolean(L, arg));
	}
	inline static std::string GetString(lua_State* L, int arg)
	{
		size_t len;
		const char* c_str = lua_tolstring(L, arg, &len);
		if (!c_str || len == 0) {
			return std::string();
		}
		return std::string(c_str, len);
	}
	inline static short GetShort(lua_State* L, int arg)
	{
		return static_cast<short>(lua_tonumber(L, arg));
	}
	inline static unsigned char GetByte(lua_State* L, int arg)
	{
		return static_cast<unsigned char>(lua_tointeger(L, arg));
	}
	inline static int GetInteger(lua_State* L, int arg)
	{
		return static_cast<int>(lua_tonumber(L, arg));
	}
	inline static float GetFloat(lua_State* L, int arg)
	{
		return static_cast<float>(lua_tonumber(L, arg));
	}
	//GetUser
	//GetMob
	//GetExtra
};

