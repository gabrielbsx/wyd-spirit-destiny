#pragma once
#include "CLuaScripts.h"
class CLuaQuest : public CLuaScripts
{
public:
	CLuaQuest(std::string luaFile, std::string funcName, int nParams, int nReturns, bool status, std::string mobName, int merch, int level) : CLuaScripts(luaFile, funcName, nParams, nReturns)
	{
		this->MobName = mobName;
		this->Merchant = merch;
		this->Level = level;
		this->Status = status;
	}
	~CLuaQuest() {};
	bool Execute(int conn, int mobID)
	{
		try
		{
			lua_getglobal(this->L, this->FunctionName.c_str());
			lua_pushnumber(this->L, conn);
			lua_pushnumber(this->L, mobID);
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
			std::cout << "MobName: " << this->MobName << " And Merchant: " << this->Merchant << " Level: " << this->Level << " CurrStatus: " << this->Status << std::endl;
			return false;
		}
	}
public:
	std::string MobName;
	int Merchant;
	int Level;
	bool Status;



};

class CQuest 
{
public:
	static bool Run(int conn, char* pMsg);
	static bool LoadScripts();
	static std::vector<CLuaQuest*> QuestScripts;
	static int TotalScripts;
};

