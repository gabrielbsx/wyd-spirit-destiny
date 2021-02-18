#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#define MOBNAME_LENGTH 16
#define MAX_EQUIPMENT 16
#define MAX_INVENTORY 64

struct STRUCT_ITEM
{
	uint16_t Index;

	struct
	{
		uint8_t Index;
		uint8_t Value;
	} Effect[3];

#define EF1 Effect[0].Index
#define EFV1 Effect[0].Value
#define EF2 Effect[1].Index
#define EFV2 Effect[1].Value
#define EF3 Effect[2].Index
#define EFV3 Effect[2].Value
};

struct STRUCT_POSITION
{
	short X;
	short Y;
};

struct STRUCT_SCORE
{
	int Level; // 0
	int Defense; // 2
	int Attack; // 4

	BYTE Merchant;
	BYTE ChaosRate;

	int maxHP, maxMP; // 8
	int curHP, curMP; // 12

	short STR, INT;
	short DEX, CON;

	short Masteries[4];
};

struct STRUCT_AFFECT
{
	uint8_t Index; // 154
	uint8_t Master; // 155
	uint16_t Value; // 156
	uint32_t Time; // 158
};

struct STRUCT_MOB
{
	char Name[MOBNAME_LENGTH];

	BYTE Kingdom;

	BYTE Merchant;

	short GuildId;

	BYTE Class;

	BYTE AffectInfo;

	BYTE QuestInfo;

	INT32 Gold;

	INT64 Exp;

	STRUCT_POSITION GemPosition;

	STRUCT_SCORE BaseStatus;

	STRUCT_SCORE CurrentStatus;

	STRUCT_ITEM Equip[MAX_EQUIPMENT];

	STRUCT_ITEM Inventory[MAX_INVENTORY];

	INT32 Learn;

	INT32 Learn2;

	unsigned short
		StatusPoint,
		MasterPoint,
		SkillPoint;

	BYTE Critical;
	BYTE SaveMana;

	char SkillBar[4];

	char GuildMemberType;

	unsigned int MagicIncrement;

	short
		RegenHP,
		RegenMP;

	short Resists[4];

	BYTE unks[200];
};

#endif