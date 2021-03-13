#include "pch.h"
#include "CAttack.h"

struct MSG_Attack
{
    unsigned short Size;
    unsigned __int8 KeyWord;
    unsigned __int8 CheckSum;
    unsigned short Type;
    unsigned short ID;
    unsigned int Tick;
    int FakeExp;
    int ReqMp;
    long long CurrentExp;
    short Rsv;
    unsigned short PosX;
    unsigned short PosY;
    unsigned short TargetX;
    unsigned short TargetY;
    unsigned short AttackerID;
    unsigned short Progress;
    unsigned char Motion;
    unsigned char FlagLocal;
    unsigned char DoubleCritical;
    unsigned char SkillParm;
    int CurrentMp;
    short SkillIndex;
    STRUCT_DAM Dam[13];
};

int CAttack::Run(unsigned short conn, char* pMsg)
{
    auto packet = reinterpret_cast<MSG_Attack*>(pMsg);


    return true;
}
