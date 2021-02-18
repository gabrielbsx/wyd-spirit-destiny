#pragma once
#include <cstdint>
#include <structs.h>

#define ACCOUNTNAME_LENGTH 16
#define MOB_PER_ACCOUNT 4

struct STRUCT_SELCHAR
{
	STRUCT_POSITION		LastPosition[MOB_PER_ACCOUNT];
	char				Name[MOB_PER_ACCOUNT][MOBNAME_LENGTH];
	STRUCT_SCORE		Status[MOB_PER_ACCOUNT];
	STRUCT_ITEM			Equip[MOB_PER_ACCOUNT][MAX_EQUIPMENT];

	int16_t				GuildId[MOB_PER_ACCOUNT];
	int32_t				Gold[MOB_PER_ACCOUNT];
	uint32_t			Experience[MOB_PER_ACCOUNT];
};

struct __declspec(align(4)) CUser
{
	char AccountName[16];
	int32_t Slot;
	uint32_t _IP;
	uint32_t Other;
	int Mode;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	STRUCT_ITEM Storage[128];
	int _Unknown_2;
	int field_474;
	int field_478;
	int field_47C;
	int field_480;
	int field_484;
	int field_488;
	int field_48C;
	int field_490;
	int field_494;
	int field_498;
	int field_49C;
	int field_4A0;
	int field_4A4;
	int field_4A8;
	int field_4AC;
	int field_4B0;
	int field_4B4;
	int field_4B8;
	int field_4BC;
	int field_4C0;
	int field_4C4;
	int field_4C8;
	int field_4CC;
	int field_4D0;
	int field_4D4;
	int field_4D8;
	int field_4DC;
	int field_4E0;
	int field_4E4;
	int field_4E8;
	int field_4EC;
	int field_4F0;
	int field_4F4;
	int field_4F8;
	int field_4FC;
	int field_500;
	int field_504;
	int field_508;
	int field_50C;
	int field_510;
	int field_514;
	int field_518;
	int field_51C;
	int field_520;
	int field_524;
	int field_528;
	int field_52C;
	int field_530;
	int field_534;
	int field_538;
	int field_53C;
	int field_540;
	int field_544;
	int field_548;
	int field_54C;
	int field_550;
	int field_554;
	int field_558;
	int field_55C;
	int field_560;
	int field_564;
	int field_568;
	int field_56C;
	int field_570;
	int field_574;
	int field_578;
	int field_57C;
	int field_580;
	int field_584;
	int field_588;
	int field_58C;
	int field_590;
	int field_594;
	int field_598;
	int field_59C;
	int field_5A0;
	int field_5A4;
	int field_5A8;
	int field_5AC;
	int field_5B0;
	int field_5B4;
	int field_5B8;
	int field_5BC;
	int field_5C0;
	int field_5C4;
	int field_5C8;
	int field_5CC;
	int field_5D0;
	int field_5D4;
	int field_5D8;
	int field_5DC;
	int field_5E0;
	int field_5E4;
	int field_5E8;
	int field_5EC;
	int field_5F0;
	STRUCT_SELCHAR SelChar;
	char _Unknown_3[80];
	struct {
		int32_t Whisper;
		int32_t Guild;
		int32_t Citzen;
		int32_t Chat;
		int32_t UnknownStatus;
		char AutoTradeName[24];
		int32_t PK;
	}AllStatus;
	struct
	{
		int32_t CountHP;
		int32_t CountMP;
		int32_t bQuaff;
	}Potion;
	int AdapterKeys[4];
	struct {
		int32_t Mode;
		int32_t Index;
		int32_t ClassId;
	}Challenger;
	int LastReceiveTime;
	int Admin;
	int Child;
	int CheckBillingTime;
	int CharLoginTime;
	char _Unknown_4[1504];
};

extern CUser* pUser;