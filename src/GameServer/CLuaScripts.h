#pragma once
#include <lua.hpp>
#include <lualib.h>
#include <string>
#include <iostream>
class CLuaScripts
{
public:
	CLuaScripts()
	{
		L = luaL_newstate();
		FunctionName = std::string();
		numArgs = 0;
		NumParams = 0;

	};
	~CLuaScripts()
	{
		if (L != nullptr)
		{
			lua_close(L);
		}
	};

	bool RegisterLua(std::string luaFile, std::string funcName, int nArgs, int nParams)
	{
		auto err = luaL_dofile(L, luaFile.c_str());
		if (err != LUA_OK)
		{
			std::cout << "Error to load file " << luaFile.c_str() << " hint error: 0x" << std::hex << std::toupper << err << std::dec << std::endl;
			std::cout << "Error: " << lua_tostring(L, -1) << std::endl;
			return false;
		}
		else
		{
			FunctionName = funcName;
			numArgs = nArgs;
			NumParams = nParams;
			luaL_openlibs(L);

			return true;
		}
	}

	lua_State* GetState()
	{
		if (this->L != nullptr)
			return this->L;
	}

private:
	lua_State* L;
	std::string FunctionName;
	int numArgs;
	int NumParams;


};
