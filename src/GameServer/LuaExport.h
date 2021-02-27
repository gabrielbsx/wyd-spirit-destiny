#pragma once
#include <lua.hpp>
/// <summary>
/// Classe responsável por gerir as funções que serão permitidas a execução no .lua
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
	/// <returns>numero de parametros que irá retornar a função</returns>
	static int Lua_Example(lua_State* L) { return 0; };

};

