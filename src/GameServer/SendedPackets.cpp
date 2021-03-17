#include "pch.h"
#include "PacketController.h"
#define PACKET_SENDSNIF 0
int PacketController::ExecuteSended(char* pMsg, DWORD* socketId, int packetSize)
{
	auto packet = reinterpret_cast<MSG_STANDARD*>(pMsg);
#if PACKET_SENDSNIF
	std::cout << "Sended Packet [0x" << std::hex << std::uppercase << packet->Type << "] " << std::dec;
	std::cout << "Size: [" << packet->Size << "] \n";
#endif
	switch (packet->Type)
	{
	case 1:
	default:
		break;
	}
	return 1;
}
