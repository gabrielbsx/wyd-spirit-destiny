#include "pch.h"
#include "PacketController.h"
#define PACKET_SENDSNIF 0
#define _TEST

struct MSG_Action
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	short PosX;
	short PosY;
	int Effect;
	int Speed;
	unsigned char Route[24];
	unsigned short TargetX;
	unsigned short TargetY;
};

int PacketController::ExecuteSended(char* pMsg, DWORD* socketId, int packetSize)
{
	auto packet = reinterpret_cast<MSG_STANDARD*>(pMsg);
#if PACKET_SENDSNIF
	std::cout << "Sended Packet [0x" << std::hex << std::uppercase << packet->Type << "] " << std::dec;
	std::cout << "Size: [" << packet->Size << "] \n";
#endif
	switch (packet->Type)
	{
	case 0x364:
		{
			auto p = reinterpret_cast<MSG_CreateMob*>(pMsg);

			if (p->MobID >= MAX_USER)
			{
#ifdef _TEST
				sprintf_s(p->Nick, "GenID: %d", pMob[p->MobID].GenerateIndex);
#endif
			}

		}
	case 0x338:
	{
		
		auto  p = reinterpret_cast<MSG_CNFMobKill*>(pMsg);
		if (p->Killer > 0 && p->Killer < MAX_MOB)
		{
			if (pMob[p->Killer].SummonerID > 0 && pMob[p->Killer].SummonerID < MAX_USER && pUser[pMob[p->Killer].SummonerID].Mode == USER_PLAY)
			{
				p->Killer = static_cast<unsigned short>(pMob[p->Killer].SummonerID);
			}
		}
		
	}
	case 0x36C:
	case 0x366:
	{
		if (packet->ID < 1000)
		{

			if (packet->Type == 0x36C ||
				packet->Type == 0x366)
			{
				auto p = reinterpret_cast<MSG_Action*>(pMsg);
				if (packet->Type == 0x366)
					std::cout << "Snd Invalido: SrcX:" << p->PosX << " SrcY:" << p->PosY << " DstX:" << p->TargetX << " DstY:" << p->TargetY << std::endl;
				else
					std::cout << "Snd Valido SrcX:" << p->PosX << " SrcY:" << p->PosY << " DstX:" << p->TargetX << " DstY:" << p->TargetY << std::endl;
			}
		}

	}
	default:
		break;
	}
	return 1;
}
