#include "pch.h"
#include "PacketController.h"
#include "CUseItem.h"
#include "CAttack.h"


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

	case 0x367:
	case 0x39D:
	case 0x39E:
		return CAttack::Run(clientID, pMsg);


	default:
		break;
	}
	return 1;
}