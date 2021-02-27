#pragma once
#include "CLuaScripts.h"
class CLuaVolatile : public CLuaScripts
{
public:

	CLuaVolatile(std::string luaFile, std::string funcName, int nParams, int nReturns, bool status, int vol, int itemId) : CLuaScripts(luaFile, funcName, nParams, nReturns)
	{
		this->Volatile = vol;
		this->ItemID = itemId;
		this->Status = status;

	};

	~CLuaVolatile() {};
	/// <summary>
	/// Responsável pela execução do scripts
	/// </summary>
	/// <param name="conn">Index do usuário na pUser</param>
	/// <returns>true = sucesso, false = erro ( envia o item para o jogador novamente )</returns>
	bool Execute(int conn)
	{
		try
		{
			lua_getglobal(this->L, this->FunctionName.c_str());
			lua_pushnumber(this->L, conn);
			auto scriptState = lua_pcall(this->L, this->NumParams, this->numReturns, 0);
			if (scriptState != LUA_OK)
			{
				printf("Error occurs when calling CLuaVolatile::Execute() Hint Machine 0x%x\n", scriptState);
				printf("Error: %s\n", lua_tostring(this->L, -1));
				return false;
			}
			return true;
		}
		catch (const std::exception& ex)
		{
			std::cout << "Failed on CUseItem::Execute returning error: " << ex.what() << std::endl;
			std::cout << "ItemIndex: " << this->ItemID << " And Volatile: " << this->Volatile << " CurrStatus: " << this->Status << std::endl;
			return false;
		}

	}
public:

	short Volatile;
	short ItemID;
	bool Status;
};

class CUseItem
{
public:
	CUseItem() {};
	~CUseItem() {};

	static bool LoadScripts();
	static int Run(int conn, char* pMsg);

public:
	/// <summary>
	/// Gerenciamento dos scripts lua
	/// </summary>
	static std::vector<CLuaVolatile*> VolatileScripts;

	static int TotalScripts;
};

