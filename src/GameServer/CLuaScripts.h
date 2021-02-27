#pragma once
#include <lua.hpp>
#include <lualib.h>
#include <string>
#include <iostream>
#include "LuaExport.h"
/// <summary>
/// Classe base dos scripts LUA
/// </summary>
class CLuaScripts
{
public:

	/// <summary>
	/// Guarda as informações do arquivo .lua
	/// </summary>
	lua_State* L;
	/// <summary>
	/// Nome da função a ser chamada quando executa o script
	/// </summary>
	std::string FunctionName;
	/// <summary>
	/// Quantidade de valores que retornam a stack.
	/// </summary>
	int numReturns;
	/// <summary>
	/// Numero de parametros passados na função
	/// </summary>
	int NumParams;

public:

	/// <summary>
	/// Construtor dos scripts
	/// </summary>
	/// <param name="luaFile">Diretório do arquivo lua</param>
	/// <param name="funcName">nome da função a ser chamada pelo script</param>
	/// <param name="nParams">numero de argumentos que leva a função.</param>
	/// <param name="nReturns">numero de retornos ( lua pode retornar mais de um valor )</param>
	CLuaScripts(std::string luaFile, std::string funcName, int nParams = 0, int nReturns = 0)
	{
		this->L = nullptr;
		this->FunctionName = "";
		this->numReturns = 0;
		this->NumParams = 0;

		this->RegisterLua(luaFile, funcName, nParams, nReturns);
	}


	~CLuaScripts()
	{

		try
		{
			if (L != nullptr)
			{
				lua_close(L);
			}
		}
		catch (const std::exception& ex)
		{

#ifdef _DEBUG
			std::cout << "Failed to destruct object CLuaScripts Error: " << ex.what() << std::endl;
#endif
		}
	};

	/// <summary>
	/// Função responsável por registrar o lua
	/// </summary>
	/// <param name="luaFile">Diretório do script lua</param>
	/// <param name="funcName">nome da função</param>
	/// <param name="nParams">numero de argumentos enviados na função</param>
	/// <param name="nReturns">numero de valores retornados pelo metodo</param>
	/// <returns></returns>
	bool RegisterLua(std::string luaFile, std::string funcName, int nParams, int nReturns)
	{
		try
		{
			this->L = luaL_newstate();

			int err = luaL_dofile(L, luaFile.c_str());
			if (err != LUA_OK)
			{
				std::cout << "Error to load file " << luaFile.c_str() << " hint error: 0x" << std::hex << std::toupper << err << std::dec << std::endl;
				std::cout << "Error: " << lua_tostring(L, -1) << std::endl;
				return false;
			}
			else
			{
				this->FunctionName = funcName;
				this->NumParams = nParams;
				this->numReturns = nReturns;
				this->RegisterFunctions();
				luaL_openlibs(this->L);

				return true;
			}
		}
		catch (const std::exception& ex)
		{
#ifdef _DEBUG
			std::cout << "Failed to load lua script: " << luaFile.c_str() << " Error:  " << ex.what() << std::endl;
#endif
			return false;
		}
	}

	/// <summary>
	/// Função responsável por registar os metodos que são acessiveis no script lua
	/// </summary>
	void RegisterFunctions()
	{
		LuaExport::InitalizeExports(this->L);
	}
};
