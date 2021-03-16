#include "pch.h"
#include "PacketController.h"
#include "CUseItem.h"
#include "CAttack.h"
#include "CWhisper.h"
#include "CQuest.h"
#include "CStoreBuy.h"
#include "CRequestSell.h"
#include "CDeleteItem.h"
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

		//Respons�vel por itens consum�veis
	case 0x373:
		return CUseItem::Run(clientID, pMsg);

		//Respons�vel por ataques
	case 0x367:
	case 0x39D:
	case 0x39E:
		return CAttack::Run(clientID, pMsg);

		//Respons�vel por comandos
	case 0x334:
		return CWhisper::Run(clientID, pMsg);

		//Respons�vel por Quests
	case 0x28B:
		return CQuest::Run(clientID, pMsg);

		//Respons�vel por compra de itens no npc
	case 0x379:
		return CStoreBuy::Run(clientID, pMsg);

		// Respons�vel por vender itens
	case 0x37A:
		return CRequestSell::Run(clientID, pMsg);

		// Respons�vel por deletar itens
	case 0x2E4:
		return CDeleteItem::Run(clientID, pMsg);

	default:
		return true;
	}
}