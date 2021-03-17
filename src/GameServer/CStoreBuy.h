#pragma once
#include "CLuaScripts.h"
class CLuaBuy : public CLuaScripts
{
public:
	CLuaBuy(std::string luaFile, std::string funcName, int nParams, int nReturns, bool status, STRUCT_ITEM item, std::string sellname) : CLuaScripts(luaFile, funcName, nParams, nReturns)
	{
		this->Item = item;
		this->SellerName = sellname;
		this->Status = status;
	}
	~CLuaBuy() {};

	bool Execute(int conn, int sellID)
	{
		try
		{
			lua_getglobal(this->L, this->FunctionName.c_str());
			lua_pushnumber(this->L, conn);
			lua_pushnumber(this->L, sellID);
			auto scriptState = lua_pcall(this->L, this->NumParams, this->numReturns, 0);
			if (scriptState != LUA_OK)
			{
				printf("Error occurs when calling CLuaBuy::Execute() Hint Machine 0x%x\n", scriptState);
				printf("Error: %s\n", lua_tostring(this->L, -1));
				return false;
			}
			return true;
		}
		catch (const std::exception& ex)
		{
			std::cout << "Failed on CStoreBuy::Execute returning error: " << ex.what() << std::endl;
			std::cout << "ItemIndex: " << this->Item.sIndex << " And SellerName: " << this->SellerName << " CurrStatus: " << this->Status << std::endl;
			return false;
		}
	}
public:
	STRUCT_ITEM Item;
	bool Status;
	std::string SellerName;
};
class CStoreBuy
{
public:
	static bool LoadScripts();
	static bool Run(int conn, char* pMsg);

private:
	static std::vector<CLuaBuy*> BuyScripts;
	static int TotalScripts;
};

