#ifndef _STRUCTS_H_
#define _STRUCTS_H_

struct CPSock
{
	unsigned int Sock;
	char* pSendBuffer;
	char* pRecvBuffer;
	int nSendPosition;
	int nRecvPosition;
	int nProcPosition;
	int nSentPosition;
	int Init;
	char SendQueue[16];
	char RecvQueue[16];
	int SendCount;
	int RecvCount;
	int ErrCount;
};

struct PacketHeader
{
	unsigned short Size;
	unsigned short Seq;
	unsigned short PacketId;
	unsigned short ClientId;
	unsigned int Tick;
};


struct MSG_UseItem : public PacketHeader
{
	int SourType, SourPos, DestType, DestPos;
	unsigned short GridX, GridY, ItemID;
};

#endif