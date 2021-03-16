#include "pch.h"
#include "CAttack.h"

int CAttack::Run(unsigned short conn, char* pMsg)
{
    auto packet = reinterpret_cast<MSG_Attack*>(pMsg);


    return true;
}
