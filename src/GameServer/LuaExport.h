#pragma once
#include <lua.hpp>
/// <summary>
/// Classe respons�vel por gerir as fun��es que ser�o permitidas a execu��o no .lua
/// </summary>
class LuaExport
{
public:
	static void InitalizeExports(lua_State* L);

private:
	/// <summary>
	/// Retorna a CMob do jogador ( precisa fixar )
	/// </summary>
	/// <param name="L">ponteiro para lua_state</param>
	/// <returns>numero de parametros que ir� retornar a fun��o</returns>
	static int Lua_Example(lua_State* L) { return 0; };

};

