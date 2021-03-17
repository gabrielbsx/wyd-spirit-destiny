#pragma once

#include "CLuaScripts.h"

class CLuaWishper : CLuaScripts
{
public:
	CLuaWishper(std::string luaFile, std::string funcName, int nParams, int nReturns, bool status, std::string command, int level) : CLuaScripts(luaFile, funcName, nParams, nReturns)
	{
		this->Command = command;
		this->Level = level;
		this->Status = status;
	}

	~CLuaWishper() {};

	bool Execute(int conn, const char* command)
	{
		try
		{
			lua_getglobal(this->L, this->FunctionName.c_str());
			lua_pushnumber(this->L, conn);
			lua_pushstring(this->L, command);
			auto scriptState = lua_pcall(this->L, this->NumParams, this->numReturns, 0);
			if (scriptState != LUA_OK)
			{
				printf("Error occurs when calling CLuaWishper::Execute() Hint Machine 0x%x\n", scriptState);
				printf("Error: %s\n", lua_tostring(this->L, -1));
				return false;
			}
			return true;
		}
		catch (const std::exception& ex)
		{
			std::cout << "Failed on CWhisper::Execute returning error: " << ex.what() << std::endl;
			std::cout << "Command: " << this->Command << " And Level: " << this->Level << " CurrStatus: " << this->Status << std::endl;
			return false;
		}
	}

public:
	bool Status;
	std::string Command;
	int Level;

};
class CWhisper
{
public:
	static bool Run(int conn, char* pMsg);
	static bool LoadScripts();


public:
	static std::vector<CLuaWishper*> CommandScripts;
	static int TotalScripts;
};

