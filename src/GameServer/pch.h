// pch.h: esse é um arquivo de cabeçalho pré-compilado.
// Os arquivos listados a seguir são compilados somente uma vez, melhorando o desempenho dos builds futuros.
// Isso também afeta o desempenho do IntelliSense, incluindo a conclusão de código e muitos recursos de navegação de código.
// No entanto, os arquivos listados aqui serão TODOS recompilados se qualquer um deles for atualizado entre builds.
// Não adicione aqui arquivos que você atualizará com frequência, pois isso anula a vantagem de desempenho.

#ifndef PCH_H
#define PCH_H

// adicione os cabeçalhos que você deseja pré-compilar aqui
#include "framework.h"

#include "GlobalPointer.h"

extern DWORD BaseAddress;

#pragma region Global defines
constexpr auto MAX_USER = 1000;
constexpr auto MAX_MOB = 12800;
constexpr auto USER_PLAY = 22;
constexpr auto MAX_ITEMLIST = 6500;
#pragma endregion


#endif //PCH_H
