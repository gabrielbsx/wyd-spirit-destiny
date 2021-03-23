#include "pch.h"
#include "PacketController.h"
#include "CUseItem.h"
#include "CAttack.h"
#include "CWhisper.h"
#include "CQuest.h"
#include "CStoreBuy.h"
#include "CRequestSell.h"
#include "CDeleteItem.h"
#include "Native.h"
unsigned char* g_pHeightMap;
#define PACKET_RECVSNIF 0

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

int PacketController::ExecuteReceived(int clientID, char* pMsg)
{
	auto packet = reinterpret_cast<MSG_STANDARD*>(pMsg);
#if PACKET_RECVSNIF
	std::cout << "Received Packet [0x" << std::hex << std::uppercase << packet->Type << "] " << std::dec;
	std::cout << "Size: [" << packet->Size << "] ";
	std::cout << "ClientID: [" << clientID << "]\n";
#endif
	switch (packet->Type)
	{

		//Responsável por itens consumíveis
	case 0x373:
		return CUseItem::Run(clientID, pMsg);

		//Responsável por ataques
	case 0x367:
	case 0x39D:
	case 0x39E:
		return CAttack::Run(clientID, pMsg);

		//Responsável por comandos
	case 0x334:
		return CWhisper::Run(clientID, pMsg);

		//Responsável por Quests
	case 0x28B:
		return CQuest::Run(clientID, pMsg);

		//Responsável por compra de itens no npc
	case 0x379:
		return CStoreBuy::Run(clientID, pMsg);

		// Responsável por vender itens
	case 0x37A:
		return CRequestSell::Run(clientID, pMsg);

		// Responsável por deletar itens
	case 0x2E4:
		return CDeleteItem::Run(clientID, pMsg);

	default:
		return true;
	}
}