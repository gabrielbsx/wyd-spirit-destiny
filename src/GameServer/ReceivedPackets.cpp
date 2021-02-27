#include "pch.h"
#include "PacketController.h"
#include "CUseItem.h"


int PacketController::ExecuteReceived(int clientID, char* pMsg)
{
	auto packet = reinterpret_cast<MSG_STANDARD*>(pMsg);
#ifdef _DEBUG
	std::cout << "Received Packet [0x" << std::hex << std::uppercase << packet->Type << "] " << std::dec;
	std::cout << "Size: [" << packet->Size << "] ";
	std::cout << "ClientID: [" << clientID << "]\n";
#endif
	switch (packet->Type)
	{
	case 0x373:
		return CUseItem::Run(clientID, pMsg);
	default:
		break;
	}
	return 1;
}