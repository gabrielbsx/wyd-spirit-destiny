#pragma once
#include <tm_structs.h>
#include "CUser.h"

class GlobalPointer
{
public:
	static bool Initialize();
};

extern CMob* pMob;
extern CUser* pUser;
extern STRUCT_ITEMLIST* g_pItemList;