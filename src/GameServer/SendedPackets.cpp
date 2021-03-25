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
	default:
		break;
	}
	return 1;
}
