#include "pch.h"
#include "Helper.h"
#include "UIHelper.h"
#include <iostream>
void Helper::ItemPrice_FormatDecimal_AutoTrade(char* gold, int value)
{
}

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

const char dwColors[][64] = { "Azul", "Vermelho", "Verde", "Prata", "Preto", "Roxo", "Marrom", "Rosa", "Amarelo", "Azul Claro" };

void __stdcall Helper::ItemDescription(int ebp, st_Item* item)
{
	int addAmount = 0;
	int colorId = 0;

	for (int i = 0; i < 3; i++)
	{

		if (item->Effect[i].Index != 0)
		{
			int addId = item->Effect[i].Index;

			if (addId < 116 && addId != 43)
				addAmount++;

			if (addId >= 116 && addId <= 125)
				colorId = 1000 + addId - 116;
		}

		if (item->Effect[i].Index == 111)
		{
			if (item->Index >= 2300 && item->Index <= 2390)
				continue;

			scene_api::AddLineToItem(ebp, "Item Imóvel", ClientColor::Yellow);
			break;
		}
	}

	if (item->Index < 2300 && item->Index > 2400)
	{
		if (addAmount == 3)
			scene_api::AddLineToItem(ebp, "Impossivel de refinar", ClientColor::Red);
	}

	if (colorId >= 1000)
	{
		if (item->Index >= 2300 && item->Index <= 2390)
			return;

		auto realColor = colorId - 1000;

		char msg[128] = { 0, };
		sprintf(msg, "Cor: %s", dwColors[realColor]);

		scene_api::AddLineToItem(ebp, msg, ClientColor::LightGreen);
	}
}

bool __stdcall Helper::NewCommands(char* command)
{
	return false;
}

bool __stdcall Helper::ItemDesc_ChangePriceString(st_Item* item, char* text)
{
	return false;
}

void __stdcall Helper::AddMessage(char* msg, int* size)
{
	auto header = reinterpret_cast<PacketHeader*>(msg);
	auto pSize = header->Size;
	if (header->PacketId == _MSG_ClientLogin_Id)
	{
		auto pLogin = reinterpret_cast<MSG_AccountLogin*>(msg);

		char errMsg[256] = { 0, };
		sprintf(errMsg, "Request:Login:%s", pLogin->AccountName);

		
		*reinterpret_cast<int*>(&msg[92]) = 778;
	}
	if (header->PacketId == _MSG_Command_Id)
	{
		auto packet = reinterpret_cast<Msg_Command*>(msg);

		// Fix /r command
		if (!strncmp(packet->Command, "r", 16) && strlen(packet->Command) == 1)
		{
			strncpy(packet->Command, "reply", 16);
		}
		else if (!strncmp(packet->Command, "fimcidadao", 16)) //Fix /fimcidadao command
		{
			strncpy(packet->Command, "getout", 16);
		}
		else if (!strncmp(packet->Command, "criar", 16)) //Fix /criar command
		{
			strncpy(packet->Command, "create", 16);
		}
		else if (!strncmp(packet->Command, "expulsar", 16)) //Fix /expulsar command
		{
			//strncpy(packet->Command, "cancellation", 16);
		}
		else if (!strncmp(packet->Command, "transferir", 16)) //Fix /transferir command
		{
			strncpy(packet->Command, "handover", 16);
		}
		else if (!strncmp(packet->Command, "gritar", 16)) //Fix /gritar command
		{
			strncpy(packet->Command, "spk", 16);
		}
		else if (!strncmp(packet->Command, "gm", 2))
		{
			packet->Header.PacketId = 0x295;
		}
	}
	if(header->PacketId == 0x36C ||
	header->PacketId == 0x366)
	{
		auto p = reinterpret_cast<MSG_Action*>(msg);
		if (header->PacketId == 0x366)
			std::cout << "Send Invalido: SrcX:" << p->PosX << " SrcY:" << p->PosY << " DstX:" << p->TargetX << " DstY:" << p->TargetY << std::endl;
		else
			std::cout << "Send Valido SrcX:" << p->PosX << " SrcY:" << p->PosY << " DstX:" << p->TargetX << " DstY:" << p->TargetY << std::endl;
		return;
	}
}

void __stdcall Helper::ReadMessage(char* msg, int* size)
{
	auto header = reinterpret_cast<PacketHeader*>(msg);
	auto pSize = header->Size;

	if (header->PacketId == _MSG_SendScore_Id)
	{
		Msg_Score_SD msg_sd;
		memcpy(&msg_sd, msg, sizeof(Msg_Score_SD));

		memset(msg, 0, sizeof(Msg_Score_SD));

		Msg_Score_BR msg_br;
		memcpy(msg_br.Chunk_1, msg_sd.Chunk_1, sizeof(msg_sd.Chunk_1));
		msg_br.Resist1 = (char)msg_sd.Resist1;
		msg_br.Resist2 = (char)msg_sd.Resist2;
		msg_br.Resist3 = (char)msg_sd.Resist3;
		msg_br.Resist4 = (char)msg_sd.Resist4;
		memcpy(msg_br.Chunk_2, msg_sd.Chunk_2, sizeof(msg_sd.Chunk_2));

		*(Msg_Score_BR*)msg = msg_br;
		*size = sizeof(Msg_Score_BR);
	}
	if (header->ClientId < 1000)
	{

		if (header->PacketId == 0x36C ||
			header->PacketId == 0x366)
		{
			auto p = reinterpret_cast<MSG_Action*>(msg);
			if (header->PacketId == 0x366)
				std::cout << "Recv Invalido: SrcX:" << p->PosX << " SrcY:" << p->PosY << " DstX:" << p->TargetX << " DstY:" << p->TargetY << std::endl;
			else
				std::cout << "Recv Valido SrcX:" << p->PosX << " SrcY:" << p->PosY << " DstX:" << p->TargetX << " DstY:" << p->TargetY << std::endl;
			return;
		}
	}
}
