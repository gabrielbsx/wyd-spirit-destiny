
#include "pch.h"
#include "LuaVolatile.h"
#include <iostream>
#include <structs.h>
#include "Native.h"
#include <ItemEffect.h>
#include "CMob.h"
#include "CUser.h"
std::vector<LuaVolatile> LuaVolatile::Scripts = std::vector<LuaVolatile>();

constexpr auto VOLATILES_DIR = "E:/Github/wyd-spirit-destiny/Server/Release/Scripts/Volatiles/";

LuaVolatile::LuaVolatile(IType Type, short RegisterID) : ILua("OnUse", 5, 1)
{
	this->myType = Type;
	this->myRegisterID = RegisterID;
}

LuaVolatile::~LuaVolatile()
{
	this->myType = IType::None;
	this->myRegisterID = 0;
}

bool LuaVolatile::OnExecute(int clientId, MSG_UseItem* pMsg)
{

	if ((pMsg->DestType == 0 && (pMsg->DestPos < 0 || pMsg->DestPos >= 16)) ||
		(pMsg->DestType == 1 && (pMsg->DestPos < 0 || pMsg->DestPos >= 64)) ||
		(pMsg->DestType == 2 && (pMsg->DestPos < 0 || pMsg->DestPos >= 128)))
		return false;

	if ((pMsg->SourType == 0 && (pMsg->SourPos < 0 || pMsg->SourPos >= 16)) ||
		(pMsg->SourType == 1 && (pMsg->SourPos < 0 || pMsg->SourPos >= 64)) ||
		(pMsg->SourType == 2 && (pMsg->SourPos < 0 || pMsg->SourPos >= 128)))
		return false;

	STRUCT_ITEM* src = GetItemPointer(&pMob[clientId], pUser[clientId].Storage, pMsg->SourType, pMsg->SourPos);

	STRUCT_ITEM* dst = GetItemPointer(&pMob[clientId], pUser[clientId].Storage, pMsg->DestType, pMsg->DestPos);


	int Vol = 0;/*GetItemAbility(src, EF_VOLATILE);*/
	Vol = 4140;
	for (auto& i : LuaVolatile::Scripts)
	{
		if (i.myType == IType::Volatile)
		{
			if (i.myRegisterID == Vol)
			{
				return !i.Execute(clientId, pMsg->SourPos, pMsg->SourType, pMsg->DestPos, pMsg->DestType);
			}
		}
		else if (i.myType == IType::Index)
		{
			if (i.myRegisterID == 4140)
			{
				return !i.Execute(clientId, pMsg->SourPos, pMsg->SourType, pMsg->DestPos, pMsg->DestType);
			}
		}
		else
		{
#ifdef _DEBUG
			std::cout << "Invalid item on LuaVolatile" << std::endl;
#endif // !_DEBUG

		}
	}
	return false;
}

void LuaVolatile::RegisterFunctions()
{
	auto state = this->GetLuaState();
	lua_register(state, "SendClientMessage", lua_SendClientMessage);
}

bool LuaVolatile::Execute(int clientId, int srcSlot, int srcType, int dstSlot, int dstType)
{
	lua_getglobal(this->GetLuaState(), this->GetMethodName().c_str());
	lua_pushnumber(this->GetLuaState(), dstType);
	lua_pushnumber(this->GetLuaState(), dstSlot);
	lua_pushnumber(this->GetLuaState(), srcType);
	lua_pushnumber(this->GetLuaState(), srcSlot);
	lua_pushnumber(this->GetLuaState(), clientId);
	lua_pcall(this->GetLuaState(), this->GetNumArgs(), this->GetNumReturn(), 0);

	return lua_toboolean(this->GetLuaState(), -1);
}

int LuaVolatile::lua_SendClientMessage(lua_State* L)
{
	const char* str = lua_tostring(L, -1);
	int clientId = static_cast<int>(lua_tointeger(L, -2));

	SendClientMessage(clientId, str);
	return 0;
}

bool LuaVolatile::LoadScripts()
{
	std::ostringstream dir{};
	dir << VOLATILES_DIR << "Volatiles.xml";

	pugi::xml_document file;

	pugi::xml_parse_result res = file.load_file(dir.str().c_str());
	if (res.status == pugi::status_ok)
	{
		pugi::xml_node volatileNode = file.child("RegisterVolatiles");
		for (pugi::xml_node vol = volatileNode.first_child(); vol; vol = vol.next_sibling())
		{
			IType nType = static_cast<IType>(vol.attribute("Type").as_int(-1));
			short nRegisterID = static_cast<short>(vol.attribute("Index").as_int(0));

			LuaVolatile newVolatile = LuaVolatile(nType, nRegisterID);
			std::string scriptName = vol.attribute("Script").as_string("");
			std::ostringstream dirScript{};
			dirScript << VOLATILES_DIR << scriptName;
			if (!newVolatile.LoadScript(dirScript.str()))
				std::cout << "Failed to load Volatile script: " << scriptName << std::endl;
			else
				LuaVolatile::Scripts.push_back(newVolatile);

		}
		return true;
	}
	return false;
}

//00526B27 Hook Addr nops 1
__declspec(naked) void LuaVolatile::NKD_Modify()
{
	__asm
	{
		MOV DWORD PTR SS : [EBP - 0x1CE4] , EAX
		PUSH EAX
		MOV EAX, DWORD PTR SS : [EBP + 0x8]
		PUSH EAX
		CALL LuaVolatile::OnExecute
		ADD ESP, 0x8
		CMP EAX, 0
		JE AbortExecution
		PUSH 0x0526B2D
		RETN
		AbortExecution :
		PUSH 0x05548F5
			RETN
	}
}


