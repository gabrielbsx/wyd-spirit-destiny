#include "pch.h"
#include "CMain.h"
#include "CHook.h"
#include "CUseItem.h"
#include "CMobKilled.h"
#include "CWhisper.h"
#include "CQuest.h"
#include "CStoreBuy.h"

bool CMain::LoadFiles()
{
	if (!CUseItem::LoadScripts()) return false;
	else if (!CMobKilled::LoadScripts()) return false;
	else if (!CWhisper::LoadScripts()) return false;
	else if (!CQuest::LoadScripts()) return false;
	else if (!CStoreBuy::LoadScripts()) return false;



	return true;
}

bool CMain::LoadHooks()
{
	return this->HookMgr->Initialize();
}
