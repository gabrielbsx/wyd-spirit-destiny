#include "pch.h"
#include "LuaMob.h"

/// <summary>
/// Responsável por inicializar a iMob
/// </summary>
/// <param name="L"></param>
void LuaMob::Initialize_MetaTable(lua_State* L)
{
	//Cria a tabela
	lua_newtable(L);
	// Pega pega em qual stack a tabela está armazenada
	int mobTableID = lua_gettop(L);
	// registra o index da tabela na stack
	lua_pushvalue(L, mobTableID);
	// atribui a variavel global
	lua_setglobal(L, "tMob");

	// importante !!!
	// sempre chamar primeiro a função e depois o nome do metodo, antes da instancia chama-se com .
	// exemplo iMob.new(mobId);
	// assim a classe irá se instanciar para um objeto
	// após finalizar a chamada da instancia, se acessa com :
	// exemplo:
	// local mob = iMob.new(id);
	// local face = mob:getFace();
	// sendo como : o acesso da referencia do objeto.
#pragma region Exports Methods

	lua_pushcfunction(L, Lua_StartMob);
	lua_setfield(L, -2, "new");

	// Exemplo de metodo da "classe"
	lua_pushcfunction(L, Lua_GetMobFace);
	lua_setfield(L, -2, "GetFace");


#pragma endregion

	// criaremos a MobMetaTable para que seja possível acessar as infos depois
	luaL_newmetatable(L, "MobMetaTable");

	// __gc é um default do destrutor da classe
	lua_pushstring(L, "__gc");
	lua_pushcfunction(L, Lua_FinishMob);
	lua_settable(L, -3);

	// usamos o __index para que não seja necessário passar como parametro a propria variavel
	// tipo, mob.MobFace(mob);
	lua_pushstring(L, "__index");
	lua_pushvalue(L, mobTableID);
	lua_settable(L, -3);

}

/// <summary>
/// Construtor do iMob no script em lua
/// </summary>
/// <param name="L"></param>
/// <returns></returns>
int LuaMob::Lua_StartMob(lua_State* L)
{
	// registramos a instancia da MetaTable com o malloc do lua (por de baixo dos panos  essa função faz o alloc e o free após o uso)
	void* mob = lua_newuserdata(L, sizeof(CMob)); 
	// usamos new para que o valor alocado não seja nulo
	new (mob) CMob();

	// os parametros são identicos ao assembly, nesse caso, usamos os valores negativos para pegar a stack de trás para frente ( dos ultimos valores registrados aos primeiros)
	// dependendo da quantidade de argumentos armazenados na stack, torna-se dificil usar os indices registrados, então o melhor a se fazer, é usar ids negativos para saber quais
	// foram os ultimos index armazenados

	//lua_tonumber retorna um double, realizamos um static_cast para que seja possível converter o float para integer
	int index = static_cast<int>(lua_tonumber(L, -2));

	// agora setamos a MetaTable com os dados da pMob utilizando o indice recuperado
	memcpy(mob, &pMob[index], sizeof(CMob));

	// após isso, precisamos identificar o nome da nossa metaTable na stack, quando identificada, automaticamente irá para o topo da pilha
	luaL_getmetatable(L, "MobMetaTable");

	// aqui iremos validar se o topo da nossa pilha é uma tabela(MetaTable), a nossa antiga tabela criada pelo newuserdata, irá descer na stack
	assert(lua_istable(L, -1));

	// feito isso, a nossa tabela irá ser definida com os dados
	lua_setmetatable(L, -2);

	// retornaremos um para identificar 
	return 1;
}

/// <summary>
/// Responsável por destruir o objeto após a execução
/// </summary>
/// <param name="L"></param>
/// <returns></returns>
int LuaMob::Lua_FinishMob(lua_State* L)
{
	CMob* mob = (CMob*)lua_touserdata(L, -1);
	mob->~CMob();
	return 0;
}

/// <summary>
/// Metodo de teste, usado apenas para checagem.
/// </summary>
/// <param name="L"></param>
/// <returns></returns>
int LuaMob::Lua_GetMobFace(lua_State* L)
{
	CMob* mob = (CMob*)lua_touserdata(L, -1);
	lua_pushnumber(L, mob->Mob.Equip[0].sIndex);
	return 1;
}