#pragma once


const int _MSG_SendScore_Id = 0x336;
const int _MSG_Command_Id = 0x334;
const int _MSG_ClientLogin_Id = 0x20D;
struct st_Item
{
	unsigned short Index;
	struct
	{
		unsigned char Index;
		unsigned char Value;
	} Effect[3];
};


struct st_ItemList
{
	char Name[64];

	short Mesh1;
	short Mesh2;

	short Unknow;

	short Level;
	short Str;
	short Int;
	short Dex;
	short Con;

	struct {
		short Index;
		short Value;
	} Effect[12];

	int Price;
	short Unique;
	unsigned short Pos;

	short Extreme;
	short Grade;
};

struct PacketHeader
{
	unsigned short Size; // 0 - 1

	unsigned char Key; // 2
	unsigned char CheckSum; // 3

	unsigned short PacketId; // 4 -5
	unsigned short ClientId; // 6 - 7

	unsigned int TimeStamp; // 8 - 11
};


struct Msg_Score_SD
{
	char Chunk_1[130];
	short Resist1;
	short Resist2;
	short Resist3;
	short Resist4;
	char Chunk_2[18];
};

struct Msg_Score_BR
{
	char Chunk_1[130];
	char Resist1;
	char Resist2;
	char Resist3;
	char Resist4;
	char Chunk_2[18];
};

struct Msg_Command
{
	PacketHeader Header;
	char Command[16];
	char Value[100];
};


struct	MSG_AccountLogin
{
	PacketHeader Header;

	char AccountPassword[12];
	char AccountName[16];

	char Zero[52];


	int  ClientVersion;

	int  DBNeedSave;

	int AdapterName[4];
};

constexpr auto GetItemList() { return (st_ItemList*)(0xFB9608); }