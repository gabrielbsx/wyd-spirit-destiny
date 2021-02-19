#include "pch.h"
#include "GlobalPointer.h"

CUser* pUser;
CMob* pMob;
STRUCT_ITEMLIST* g_pItemList;
bool GlobalPointer::Initialize()
{
	try
	{
		pUser = reinterpret_cast<CUser*>(BaseAddress + 0x5CF9AB8);
		pMob = reinterpret_cast<CMob*>(BaseAddress + 0x078D3AC0);
		g_pItemList = reinterpret_cast<STRUCT_ITEMLIST*>(BaseAddress + 0x04AE600);
		//pMobGrid[4096][4096] 0x04B1000
		//pItemGrid[4096][4096] 0x028CD258
		sizeof(STRUCT_ITEMLIST);
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}

}
