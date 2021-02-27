#include "pch.h"
#include "CMain.h"
#include "CUseItem.h"

bool CMain::LoadFiles()
{
	if (!CUseItem::LoadScripts())
		return false;



	return true;
}