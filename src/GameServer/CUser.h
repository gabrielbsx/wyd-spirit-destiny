#pragma once
#include <cstdint>
#include <structs.h>

#define ACCOUNTNAME_LENGTH 16
#define ACCOUNTPASS_LENGTH 12
#define MOB_PER_ACCOUNT 4

struct MSG_Trade
{
	unsigned __int16 Size;
	unsigned __int8 KeyWord;
	unsigned __int8 CheckSum;
	unsigned __int16 Type;
	unsigned __int16 ID;
	unsigned int Tick;
	STRUCT_ITEM Item[15];
	char CarryPos[15];
	int TradeMoney;
	unsigned __int8 MyCheck;
	unsigned __int16 OpponentID;
};

struct MSG_AutoTrade
{
	unsigned __int16 Size;
	unsigned __int8 KeyWord;
	unsigned __int8 CheckSum;
	unsigned __int16 Type;
	unsigned __int16 ID;
	unsigned int Tick;
	char Desc[24];
	STRUCT_ITEM Item[12];
	char CarryPos[12];
	int TradeMoney[12];
	unsigned __int16 Tax;
	unsigned __int16 TargetID;
};

class CUser
{
public:
	char AccountName[16]; // 0 - 15 = 61AAAB8
	int Slot; // 16 - 19 = 61AAAC8
	unsigned int IP; // 20 - 23 = 61AAACC
	int Mode; // 24 - 27 = 61AAAD0
	int TradeMode; // 28 - 31 = 61AAAD4
	CPSock cSock; // 32 - 107 = 61AAAD8
	STRUCT_ITEM Cargo[128]; // 108 - 1131 = 61AAB24
	int Coin; // 1132 - 1135 = 61AAF24
	unsigned short cProgress; // 1136 - 1137 = 61AAF28
	short UnknowByte_1138; // 1138 - 1139 = 61AAF2A
	MSG_Trade Trade; // 1140 - 1295 = 61AAF2C
	MSG_AutoTrade AutoTrade; // 1296 - 1491 = 61AAFC8
	int LastAttack; // 1492 - 1495 = 61AB08C
	unsigned int LastAttackTick; // 1496 - 1499 = 61AB090
	int LastMove; // 1500 - 1503 = 61AB094
	int LastAction; // 1504 - 1507 = 61AB098
	unsigned int LastActionTick; // 1508 - 1511 = 61AB09C
	unsigned int LastIllusionTick; // 1512 - 1515 = 61AB0A0
	unsigned int NumError; // 1516 - 1519 = 61AB0A4
	STRUCT_SELCHAR SelChar; // 1520 - 2359 = 61AB0A8
	char LastChat[16]; // 2360 - 2375 = 61AB3F0
	char Session[36]; // 2376 - 2411 = 61AB400
	unsigned char CharShortSkill[16]; // 2412 - 2427 = 61AB424
	int nTargetX; // 2428 - 2431 = 61AB434
	int nTargetY; // 2432 - 2435 = 61AB438
	int Whisper; // 2436 - 2439 = 61AB43C
	int Guildchat; // 2440 - 2443 = 61AB440
	int PartyChat; // 2444 - 2447 = 61AB444
	int Chatting; // 2448 - 2451 = 61AB448
	int UnknowByte_2452; // 2452 - 2455 = 61AB44C
	char AutoTradeName[24]; // 2456 - 2479 = 61AB450
	int PKMode; // 2480 - 2483 = 61AB468
	int ReqHp; // 2484 - 2487 = 61AB46C
	int ReqMp; // 2488 - 2491 = 61AB470
	int bQuaff; // 2492 - 2495 = 61AB474
	char Mac[16]; // 2496 - 2511 = 61AB478
	int RankingMode; // 2512 - 2515 = 61AB488
	int RankingTarget; // 2516 - 2519 = 61AB48C
	int RankingType; // 2520 - 2523 = 61AB490
	int LastReceiveTime; // 2524 - 2527 = 61AB494
	int Admin; // 2528 - 2531 = 61AB498
	int Child; // 2532 - 2535 = 61AB49C
	unsigned int CheckBillingTime; // 2536 - 2539 = 61AB4A0
	int CharLoginTime; // 2540 - 2543 = 61AB4A4
	int CastleStatus; // 2544 - 2547 = 61AB4A8
	unsigned int LogoutTime; // 2548 - 2551 = 61AB4AC
	unsigned int RecallTime; // 2552 - 2555 = 61AB4B0
	unsigned int RestartTime; // 2556 - 2559 = 61AB4B4
	int UnknowByte_2560; // 2560 - 2563 = 61AB4B8
	int UnknowByte_2564; // 2564 - 2567 = 61AB4BC
	int UnknowByte_2568; // 2568 - 2571 = 61AB4C0
	char SecretCode[16]; // 2572 - 2587 = 61AB4C4
	int UnknowByte_2588; // 2588 - 2591 = 61AB4D4
	int UnknowByte_2592; // 2592 - 2595 = 61AB4D8
	int UnknowByte_2596; // 2596 - 2599 = 61AB4DC
	int UnknowByte_2600; // 2600 - 2603 = 61AB4E0
	int UnknowByte_2604; // 2604 - 2607 = 61AB4E4
	int UnknowByte_2608; // 2608 - 2611 = 61AB4E8
	int UnknowByte_2612; // 2612 - 2615 = 61AB4EC
	int UnknowByte_2616; // 2616 - 2619 = 61AB4F0
	int UnknowByte_2620; // 2620 - 2623 = 61AB4F4
	int UnknowByte_2624; // 2624 - 2627 = 61AB4F8
	int UnknowByte_2628; // 2628 - 2631 = 61AB4FC
	int UnknowByte_2632; // 2632 - 2635 = 61AB500
	int UnknowByte_2636; // 2636 - 2639 = 61AB504
	int UnknowByte_2640; // 2640 - 2643 = 61AB508
	char dummy[52]; // 2644 - 2695 = 61AB50C
	int UnknowByte_2696; // 2696 - 2699 = 61AB540
	int UnknowByte_2700; // 2700 - 2703 = 61AB544
	char Snd[128]; // 2704 - 2831 = 61AB548
	int UnknowByte_2832; // 2832 - 2835 = 61AB5C8
	int UnknowByte_2836; // 2836 - 2839 = 61AB5CC
	int UnknowByte_2840; // 2840 - 2843 = 61AB5D0
	int UnknowByte_2844; // 2844 - 2847 = 61AB5D4
	int UnknowByte_2848; // 2848 - 2851 = 61AB5D8
	int UnknowByte_2852; // 2852 - 2855 = 61AB5DC
	int UnknowByte_2856; // 2856 - 2859 = 61AB5E0
	int UnknowByte_2860; // 2860 - 2863 = 61AB5E4
	int UnknowByte_2864; // 2864 - 2867 = 61AB5E8
	int UnknowByte_2868; // 2868 - 2871 = 61AB5EC
	int UnknowByte_2872; // 2872 - 2875 = 61AB5F0
	int UnknowByte_2876; // 2876 - 2879 = 61AB5F4
	int UnknowByte_2880; // 2880 - 2883 = 61AB5F8
	int UnknowByte_2884; // 2884 - 2887 = 61AB5FC
	int UnknowByte_2888[36]; // 2888 - 3031 = 61AB600
	int UnknowByte_3032; // 3032 - 3035 = 61AB690
	int UnknowByte_3036; // 3036 - 3039 = 61AB694
	int UnknowByte_3040; // 3040 - 3043 = 61AB698
	int LastSkillTick[248]; // 3044 - 4035 = 61AB69C
	int UnknowByte_4036; // 4036 - 4040 = 61ABA7C
};
