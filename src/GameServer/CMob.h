#pragma once
#include <structs.h>
#include <cstdint>
#define MAX_AFFECT 32
#define MAX_PARTY 12

struct Info_soul1 {
	char cele : 4;
	char sub : 4;
};

struct Info_
{
	//		uint8_t		_Unknown[16];
	//STRUCT_ITEM _u[2];
//	uint32_t	QuestInfo; // 1FDF034
	uint8_t		QuestInfo[4];
	uint8_t		Citzenship; // 1FDF038 -> Cidadania!!!
	uint8_t		_u1[4]; // 1FDF039
	uint8_t		HasSub; // 1FDF03D ?? 

	Info_soul1 soul1;

	uint8_t		isSubOn; // 1FDF03F
	uint8_t		_u4[4]; // 1FDF040

	uint32_t	Learn; // 1FDF044

	STRUCT_ITEM CeleFace; // 1FDF048
	STRUCT_SCORE SubScore; // 1FDF050
	uint32_t	SubExp; // 1FDF06C
	char		SubSkillBar[4]; // 1FDF070
	char		SubSkillBar2[16]; // 1FDF074
	int16_t		SubStatusPoint; // 1FDF084
	int16_t		SubMasterPoint; // 1FDF086
	uint32_t	SubLearn; // 1FDF088
	STRUCT_ITEM SubFace; //	1FDF08C

	uint8_t		_Unknown_2[84];

	uint32_t CytheraBonus; // 1FDF0E0

	uint8_t		_Unknown_3[104];
}; // Size 288


struct CMob 
{
	STRUCT_MOB Mob;
	uint32_t CPoint; // 1028
	uint32_t CrackError; //1032
	uint32_t NTCount; // 1036
	uint32_t Mileage; // 1040
	uint32_t Unknown_1FDEFA4; // 1044
	uint32_t Fame; // 1048
	uint32_t KefraTp; // 1052
	uint32_t Unknown_1FDEFB0; // 1056

	STRUCT_AFFECT SaveAffects[MAX_AFFECT]; // 0x1FDEFB4

	Info_ Info;

	STRUCT_AFFECT Affects[MAX_AFFECT]; // 0x1FDF154

	uint32_t Mode; // 1D4
	uint32_t Leader; // 1D8

	uint32_t Formation; // 1DC
	uint32_t RouteType; // 1E0

	int32_t LastPosX; // 1E4
	int32_t LastPosY; // 1E8

	uint32_t LastTime; // 1EC
	uint32_t LastSpeed; // 1F0

	int32_t PosX; // 1FDF1F4
	int32_t PosY; // 01FDF1F8

	uint8_t Unknown_01FDF1FC[128];

	uint32_t Unknown_01FDF278;

	int32_t GenerateIndex; // 01FDF27C 
	uint16_t CurrentTarget; // 01FDF280
	int16_t EnemyList[2]; // 01FDF282 
	int16_t PartyList[MAX_PARTY]; // 01FDF28A
	char unknown[2];
	int16_t Unknown_01FDF2A2;

	uint32_t WeaponDamage; // 01FDF2A4
	uint32_t Summoner; // 01FDF2A8
	uint32_t PotionCount; // 01FDF2AC
	uint32_t GuildDisable; // 01FDF2B0

	uint32_t Parry; // 01FDF2B4
	uint32_t ExpBonus; // 01FDF2B8
	uint32_t DropBonus; // 01FDF2BC
	uint32_t ForceBonus; // 01FDF2C0

	uint32_t FaceInfo; // 01FDF2C8
	uint32_t Unknown_01FDF2CC; // 01FDF2CC

	uint8_t Unknown_01FDF2D0[76]; // 01FDF2D0

	char Tab[26]; // 01FDF31C

	uint8_t Unknown_01FDF336[22]; // 01FDF336
	uint32_t unkBuff; // 01FDF34C
	uint8_t Unknow_01FDF350[12]; // 01FDF350

	char unkDif[328];
	//Precisa ver o que essa struct tem...
};

extern CMob* pMob;