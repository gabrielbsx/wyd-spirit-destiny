#pragma once
#include <structs.h>
#include <tm_structs.h>
#ifndef _NATIVE_H_
#define _NATIVE_H_

#pragma region Items
//STRUCT_ITEM* __cdecl sub_(CMob* a1, STRUCT_ITEM* a2, int srcType, int srcPos)

static STRUCT_ITEM* (*GetItemPointer)(CMob* mob, STRUCT_ITEM* cargo, int slotType, int Slot) = (STRUCT_ITEM * (__cdecl*)(CMob*, STRUCT_ITEM*, int, int))  0x004BA5C0; // 
static int (*GetItemAbility)(STRUCT_ITEM* item, int effect) = (int(__cdecl*)(STRUCT_ITEM*, int)) 0x004B7FD0; // 
static void	(*SendClientMessage)(int connId, const char* message) = (void(__cdecl*)(int, const char*)) 0x05016D0;
#pragma endregion


#endif // !_NATIVE_H_
