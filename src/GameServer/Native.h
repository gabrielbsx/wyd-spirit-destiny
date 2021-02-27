#pragma once
#include <structs.h>

#ifndef _NATIVE_H_
#define _NATIVE_H_

#pragma region Items
static STRUCT_ITEM* (*GetItemPointer)(CMob* mob, STRUCT_ITEM* cargo, int slotType, int Slot) = (STRUCT_ITEM * (__cdecl*)(CMob*, STRUCT_ITEM*, int, int))  0x004BA5C0;
static int (*GetItemAbility)(STRUCT_ITEM* item, int effect) = (int(__cdecl*)(STRUCT_ITEM*, int)) 0x004B7FD0; // 
static void	(*SendClientMessage)(int connId, const char* message) = (void(__cdecl*)(int, const char*)) 0x05016D0;
// int GetCityzen(int connId); 0x4DFCE0
// int GetCreateMob(int connId, char* pMsg); 0x4DD640
// int GetCreateMobTrade(int connId, char* pMsg); 0x4DE0D0
// bool GetRoute(int a1, int a2, int *a3, int *a4, int a5, int a6, int a7, int a8) 0x4C14E0
// int GetDistance(int x1, int y1, int x2, int y2) 0x4B1983
// int __thiscall GetEvolution(CMob*this); 0x04D1170
// int __thiscall CheckGetLevel(CMob*this); 0x4D0300 
// void __thiscall GetCurrentScore(CMob*this, int connId); 0x04CE1C0
// int64 SendScore(int connId); 0x504ED0
// int GetItemAbillity1(STRUCT_ITEM* item,unsigned char Effect); 0x4B7FD0
// int GetItemAbillity2(STRUCT_ITEM* item,unsigned char Effect); 0x4B8FE0
// int GetItemAbillity3(STRUCT_ITEM* item,unsigned char Effect); 0x4B88E0
// int GetMobAbillity1(STRUCT_MOB* mob,unsigned char Effect); 0x4BAB80 
// int GetMobAbillity2(STRUCT_MOB* mob,unsigned char Effect); 0x4BA690  
// int GetEmptyMobGrid(int a1, int *a2, int *a3, int a4); 0x4E0740
// int GetMobSpeed(STRUCT_SCORE* score); 0x4B7190
// int GetEmptyAffectSlot(int connId, int EffectID); 0x4DC180
// int GetItemSanc(STRUCT_ITEM* item); 0x04B97F0
// int GetItemSanc(STRUCT_ITEM* item); 0x4B9C20
// int SetItemSanc(STRUCT_ITEM* item, int sanc, int GemBonus); 0x4B9FE0
// int GetItemPrice(STRUCT_ITEM* item, int Gold); 0x4B5BF0
// STRUCT_ITEM* SetItemAmount(STRUCT_ITEM* item, int value); 0x4BA290
// void SendClientMessageCode(int connId, char unk, int Code); 0x508130
// int GetItemAmount(STRUCT_ITEM* item); 0x4B17D5
// void AddLog(char* Message, char* login, int* ip); 0x4B308F
// unsigned char* SetItemDate(STRUCT_ITEM* item, int Days); 0x57B070
// void SendItem(int connId, int SlotType, STRUCT_ITEM * item); 0x5045E0
// void SetQuestFlag(char* Quest, int Flag); 0x4B253B
// bool CheckQuestFlag(char* Quest, int Flag); 0x4B24EB
// int64 SendSignalParam(int connId, int index, short Packet,  int Value1);0x4B1AF5
// bool GetExtraCarry(STRUCT_ITEM* carry, int pos); 0x4BEB70
// int SetAffect(int connId, int Effect, int Time, int Special); 0x4B223E
// int64 SendEmotion(int connId, short param1, short param2); 0x503F20
// int64 PossbileUpdateModGrid(int connId, int TargetId); 0x4B25C2
// int64 SendItem(int connId, short Slot, int unk);0x503F20
#pragma endregion


#endif // !_NATIVE_H_
