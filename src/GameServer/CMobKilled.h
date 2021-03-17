#pragma once
#include "CLuaScripts.h"
class CLuaMobKilled : public CLuaScripts
{
public:
	CLuaMobKilled(std::string luaFile, std::string funcName, int nParams, int nReturns, bool status, std::string mobName, int genID) : CLuaScripts(luaFile, funcName, nParams, nReturns)
	{
		this->MobName = mobName;
		this->GenerID = genID;
		this->Status = status;
	}
	~CLuaMobKilled() {};

	std::string MobName;
	int GenerID;
	bool Status;

	bool Execute(int conn, int killed)
	{
		try
		{
			lua_getglobal(this->L, this->FunctionName.c_str());
			lua_pushnumber(this->L, conn);
			lua_pushnumber(this->L, killed);
			auto scriptState = lua_pcall(this->L, this->NumParams, this->numReturns, 0);
			if (scriptState != LUA_OK)
			{
				printf("Error occurs when calling CLuaMobKilled::Execute() Hint Machine 0x%x\n", scriptState);
				printf("Error: %s\n", lua_tostring(this->L, -1));
				return false;
			}
			return true;
		}
		catch (const std::exception& ex)
		{
			std::cout << "Failed on CMobKilled::Execute returning error: " << ex.what() << std::endl;
			std::cout << "MobName: " << this->MobName << " And GenerateIndex: " << this->GenerID << " CurrStatus: " << this->Status << std::endl;
			return false;
		}
	}


};

class CMobKilled
{
public:
	static void NKD_Modify();
	static int Execute(int killer, int killed, int posX, int posY);
	static bool LoadScripts();

	static std::vector<CLuaMobKilled*> MobKilledScripts;
	static int TotalScripts;
};

