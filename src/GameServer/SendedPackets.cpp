#include "pch.h"
#include "PacketController.h"
#define PACKET_SENDSNIF 0
#define _TEST
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
	default:
		break;
	}
	return 1;
}
