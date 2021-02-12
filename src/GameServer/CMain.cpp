#include "pch.h"
#include "CHook.h"
#include "CMain.h"


CMain* g_pMain = nullptr;

CMain::CMain()
{
    this->HookMgr = new CHook();
    g_pMain = this;
}

CMain::~CMain()
{
    if (this->HookMgr != nullptr)
        delete[] this->HookMgr;

    delete[] this;
}

bool CMain::Initialize()
{
    return this->HookMgr->Initialize() & this->LoadFiles();
}

bool CMain::LoadFiles()
{
    return true;
}

