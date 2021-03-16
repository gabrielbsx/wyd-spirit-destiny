#pragma once
#include <structs.h>

#ifndef _NATIVE_H_
#define _NATIVE_H_

#pragma region Basedef

static int (*BASE_WriteItemPrice)() = (int(__cdecl*)()) 0x4B57F0;
static int (*BASE_WriteItemPrice)() = (int(__cdecl*)()) 0x4B57F0;
static bool (*BASE_CheckBit)(char*, int) = (bool(__cdecl*)(char* Quest, int value)) 0x4B5A90;
static bool (*BASE_SetBit)(char*, int) = (bool(__cdecl*)(char* Quest, int value)) 0x4B5B00;
static bool (*BASE_ResetBit)(char*, int) = (bool(__cdecl*)(char* Quest, int value)) 0x4B5B70;
static bool (*BASE_NeedLog)(STRUCT_ITEM*, int) = (bool(__cdecl*)(STRUCT_ITEM * Quest, int price)) 0x4B5BF0;
static int (*BASE_GetBonusScorePoint)(STRUCT_MOB*, int, STRUCT_EXT2*) = (int(__cdecl*)(STRUCT_MOB * mob, int face, STRUCT_EXT2 * ext2)) 0x4B6580;
static int (*BASE_GetBonusSkillPoint)(STRUCT_MOB*, int) = (int(__cdecl*)(STRUCT_MOB * mob, int face)) 0x4B6310;
static int (*BASE_GetBonusSpecialPoint)(STRUCT_MOB*, int) = (int(__cdecl*)(STRUCT_MOB * mob, int face)) 0x4B6E90;
static int (*BASE_GetAC)(STRUCT_MOB*, int) = (int(__cdecl*)(STRUCT_MOB * mob, int face)) 0x4B6FF0;
static int (*BASE_GetHpMp)(STRUCT_MOB*, int) = (int(__cdecl*)(STRUCT_MOB * mob, int face)) 0x4B7060;
static int (*BASE_GetSpeed)(STRUCT_SCORE*) = (int(__cdecl*)(STRUCT_SCORE * score)) 0x4B7190;
static int (*BASE_GetDamage)(int, int, int) = (int(__cdecl*)(int dam, int ac, int combat)) 0x4B71F0;
static int (*BASE_GetSkillDamage)(int, STRUCT_MOB*, int, int, int) = (int(__cdecl*)(int skillnum, STRUCT_MOB * mob, int weather, int weapondamage, int OriginalFace)) 0x4C3DE0;
static int (*BASE_GetSkillDamage_2)(int, int, int) = (int(__cdecl*)(int dam, int ac, int combat)) 0x4B76A0;
static int (*BASE_GetItemFromString)(STRUCT_ITEM*, char*) = (int(__cdecl*)(STRUCT_ITEM * item, char* str)) 0x4B7790;
static int (*BASE_GetItemCode)(STRUCT_ITEM*, char*) = (int(__cdecl*)(STRUCT_ITEM * item, char* str)) 0x4B7910;
static int (*BASE_GetItemAbility)(STRUCT_ITEM*, unsigned char) = (int(__cdecl*)(STRUCT_ITEM * item, unsigned char Type)) 0x4B7FD0;
static int (*BASE_GetStaticItemAbility)(STRUCT_ITEM*, unsigned char) = (int(__cdecl*)(STRUCT_ITEM * item, unsigned char Type)) 0x4B88E0;
static int (*BASE_GetBonusItemAbility)(STRUCT_ITEM*, unsigned char) = (int(__cdecl*)(STRUCT_ITEM * item, unsigned char Type)) 0x4B8FE0;
static void (*BASE_SetColorArmor)(STRUCT_ITEM*, int) = (void(__cdecl*)(STRUCT_ITEM * item, int color)) 0x4B9520;
static int (*BASE_GetItemSanc)(STRUCT_ITEM*) = (int(__cdecl*)(STRUCT_ITEM * item)) 0x4B97F0;
static int (*BASE_GetItemSancEffect)(STRUCT_ITEM*) = (int(__cdecl*)(STRUCT_ITEM * item)) 0x4B9A30;
static int (*BASE_GetItemSancSuccess)(STRUCT_ITEM*) = (int(__cdecl*)(STRUCT_ITEM * item)) 0x4B9C20;
static int (*BASE_GetSuccessRate)(STRUCT_ITEM*, int) = (int(__cdecl*)(STRUCT_ITEM * item, int OriLacto)) 0x4B9E00;
static int (*BASE_GetGrowthRate)(STRUCT_ITEM*) = (int(__cdecl*)(STRUCT_ITEM * item)) 0x4B9F70;
static int (*BASE_SetItemSanc)(STRUCT_ITEM*, int, int) = (int(__cdecl*)(STRUCT_ITEM * dest, int sanc, int success)) 0x4B9FE0;
static int (*BASE_GetItemAmount)(STRUCT_ITEM*) = (int(__cdecl*)(STRUCT_ITEM * item)) 0x4BA200;
static void (*BASE_SetItemAmount)(STRUCT_ITEM*, int) = (void(__cdecl*)(STRUCT_ITEM * item, int amount)) 0x4BA290;
static bool (*BASE_SumItemAmount)(STRUCT_ITEM*, STRUCT_ITEM*) = (bool(__cdecl*)(STRUCT_ITEM * sour, STRUCT_ITEM * dest)) 0x4BA420;
static STRUCT_ITEM* (*GetItemPointer)(STRUCT_MOB*, STRUCT_ITEM*, int, int) = (STRUCT_ITEM * (__cdecl*)(STRUCT_MOB * mob, STRUCT_ITEM * cargo, int type, int pos)) 0x4BA5C0;
static int (*BASE_GetMobAbility)(STRUCT_ITEM*, unsigned char) = (int(__cdecl*)(STRUCT_ITEM * item, unsigned char Type)) 0x4BA690;
static int (*BASE_GetMaxAbility)(STRUCT_ITEM*, unsigned char) = (int(__cdecl*)(STRUCT_ITEM * item, unsigned char Type)) 0x4BAB80;
static char (*BASE_CheckValidString)(char*) = (char(__cdecl*)(char* name)) 0x4BAD20;
static int (*BASE_OnlyUseEngString)(char*) = (int(__cdecl*)(char* str)) 0x4BAE10;
static int (*BASE_InitializeBaseDef)() = (int(__cdecl*)()) 0x4BB0A0;
static void (*BASE_ApplyAttribute)(char*, int) = (void(__cdecl*)(char* pHeight, int size)) 0x4BB140;
static void (*BASE_InitModuleDir)() = (void(__cdecl*)()) 0x4BB220;
static void (*BASE_UnderBarToSpace)(char*) = (void(__cdecl*)(char* szStr)) 0x4BB3A0;
static void (*BASE_GetCurrentScore)(STRUCT_MOB*, STRUCT_AFFECT*, STRUCT_EXT1*, STRUCT_EXT2*, int, int, int, int*, int, int*) = (void(__cdecl*)(STRUCT_MOB * MOB, STRUCT_AFFECT * Affect, STRUCT_EXT1 * Ext1, STRUCT_EXT2 * Ext2, int OriginalFace, int TargetX, int TargetY, int* AnotherSkill, int soultype, int* BuffState)) 0x4BB4C0;
static int (*BASE_GetSubGuild)(int) = (int(__cdecl*)(int item)) 0x4BE400;
static int (*BASE_GetVillage)(int, int) = (int(__cdecl*)(int x, int y)) 0x4BE270;
static int (*BASE_GetVillage2)(int, int) = (int(__cdecl*)(int x, int y)) 0x4BE590;
static int (*BASE_GetGuild)(int, int) = (int(__cdecl*)(int x, int y)) 0x4BE300;
static int (*BASE_GetArena)(int, int) = (int(__cdecl*)(int x, int y)) 0x4BE460;
static void (*BASE_ClearItem)(STRUCT_ITEM*) = (void(__cdecl*)(STRUCT_ITEM * item)) 0x4BE670;
static int (*BASE_CanEquip)(STRUCT_ITEM*, STRUCT_SCORE*, int, int, STRUCT_ITEM*, int, int) = (int(__cdecl*)(STRUCT_ITEM * item, STRUCT_SCORE * score, int Pos, int Class, STRUCT_ITEM * pBaseEquip, int OriginalFace, int cktrans)) 0x4BE6D0;
static int (*BASE_CanCarry)(STRUCT_ITEM*, int) = (int(__cdecl*)(STRUCT_ITEM * Carry, int pos)) 0x4BEB70;
static int (*BASE_CanCargo)(STRUCT_ITEM*, STRUCT_ITEM*, int, int) = (int(__cdecl*)(STRUCT_ITEM * item, STRUCT_ITEM * cargo, int DestX, int DestY)) 0x4BEBF0;
static void (*BASE_SortTradeItem)(STRUCT_ITEM*, int) = (void(__cdecl*)(STRUCT_ITEM * Item, int Type)) 0x4BEC40;
static int (*BASE_CanTrade)(STRUCT_ITEM*, STRUCT_ITEM*, unsigned char*, STRUCT_ITEM*) = (int(__cdecl*)(STRUCT_ITEM * Dest, STRUCT_ITEM * Carry, unsigned char* MyTrade, STRUCT_ITEM * OpponentTrade)) 0x4BEE30;
static void (*BASE_InitializeMessage)(char*) = (void(__cdecl*)(char* file)) 0x4BF030;
static void (*BASE_InitializeMobname)(char*) = (void(__cdecl*)(char* file)) 0x4BF410;
static void (*BASE_InitializeItemList)(char*) = (void(__cdecl*)(char* file)) 0x4BF760;
static int (*BASE_ReadItemName)(char*) = (int(__cdecl*)(char* file)) 0x4BF880;
static int (*BASE_ReadItemListFile)(char*, int) = (int(__cdecl*)(char* file, int mode)) 0x4BFD60;
static void (*BASE_InitializeEffectName)() = (void(__cdecl*)()) 0x4C07F0;
static void (*BASE_InitializeHitRate)() = (void(__cdecl*)()) 0x4C0B20;
static int (*BASE_UpdateItem)(int, int, int, int, int, char*, int, int*) = (int(__cdecl*)(int maskidx, int CurrentState, int NextState, int xx, int yy, char* pHeight, int rotate, int* height)) 0x4C0C80;
static int (*BASE_GetManaSpent)(int, int, int) = (int(__cdecl*)(int SkillNumber, int SaveMana, int Special)) 0x4C1190;
static int (*BASE_GetDoubleCritical)(STRUCT_MOB*, unsigned short*, unsigned short*, unsigned char*) = (int(__cdecl*)(STRUCT_MOB * mob, unsigned short* sProgress, unsigned short* cProgress, unsigned char* bDoubleCritical)) 0x4C13A0;
static bool (*BASE_GetRoute)(int, int, int*, int*, char*, int, char*, int) = (bool(__cdecl*)(int x, int y, int* targetx, int* targety, char* Route, int distance, char* pHeight, int MH)) 0x4C14E0;
static int (*BASE_GetDistance)(int, int, int, int) = (int(__cdecl*)(int x1, int y1, int x2, int y2)) 0x4C2050;
static void (*BASE_GetHitPosition)(int, int, int*, int*, char*, int) = (void(__cdecl*)(int sx, int sy, int* tx, int* ty, char* pHeight, int MH)) 0x4C20F0;
static void (*BASE_InitializeInitItem)() = (void(__cdecl*)()) 0x4C2CD0;
static void (*BASE_InitializeSkill)() = (void(__cdecl*)()) 0x4C2F90;
static bool (*IsClearString3)(char*, int) = (bool(__cdecl*)(char* str, int nTarget)) 0x4C3400;
static int (*BASE_InitializeServerList)() = (int(__cdecl*)()) 0x4C37D0;
static int (*BASE_InitializeServerListFile)() = (int(__cdecl*)()) 0x4C3950;
static int (*BASE_InitializeAttribute)() = (int(__cdecl*)()) 0x4C3C80;
static int (*BASE_GetEnglish)(char*) = (int(__cdecl*)(char* name)) 0x4C4540;
static int (*BASE_ReadGameRoomIP)() = (int(__cdecl*)()) 0x4C4680;
static int (*BASE_ReadBlockIP)() = (int(__cdecl*)()) 0x4C48F0;
static unsigned int (*BASE_GetWeekNumber)() = (unsigned int(__cdecl*)()) 0x4C4B60;
static bool (*BASE_CheckQuestBit)(char, int) = (bool(__cdecl*)(char quest, int index)) 0x4C4BA0;
static void (*BASE_SetQuestBit)(char*, int) = (void(__cdecl*)(char* quest, int index)) 0x4C4BF0;
static void (*BASE_CleanQuestBit)(char*, int) = (void(__cdecl*)(char* quest, int index)) 0x4C4C50;
static bool (*BASE_GetCheckFace)(int) = (bool(__cdecl*)(int face)) 0x4C61D0;
static int (*BASE_GetClan)(int) = (int(__cdecl*)(int mantle)) 0x4C6220;
static int (*BASE_GetMandleLev)(int) = (int(__cdecl*)(int mantle)) 0x4C6350;
static int (*BOOL_CanRepurchase)(STRUCT_REPURCHASEITEM*) = (int(__cdecl*)(STRUCT_REPURCHASEITEM * pRepurchase)) 0x4C6A00;
static int (*BASE_GetCouponPrice)(STRUCT_ITEM*) = (int(__cdecl*)(STRUCT_ITEM* cupom)) 0x4C7950;
// BASE_NotUsed 0x4C7380
// BASE_NotUsed2 0x4C73F0

#pragma endregion

#pragma region Server
static void	(*SendClientMessage)(int connId, const char* message) = (void(__cdecl*)(int, const char*)) 0x05016D0;
static int	(*SendNotice)(const char* message) = (int(__cdecl*)(const char*)) 0x0501900;
static int	(*DoTeleport)(int conn, int posX, int posY, int unk) = (int(__cdecl*)(int conn, int posX, int posY, int)) 0x04B2473;

#pragma endregion


#endif // !_NATIVE_H_
