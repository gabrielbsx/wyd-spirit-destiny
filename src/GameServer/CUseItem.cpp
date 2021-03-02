#include "pch.h"
#include "CUseItem.h"
#include "Native.h"
std::string ScriptVolatileDir = "../../Settings/Scripts/Volatiles"; // Register.xml

std::vector<CLuaVolatile*> CUseItem::VolatileScripts = std::vector<CLuaVolatile*>();
int CUseItem::TotalScripts = 0;



constexpr auto NUM_ARGS_USEITEM = 1;
constexpr auto NUM_RETURN_USEITEM = 0;

bool CUseItem::LoadScripts()
{
	CUseItem::VolatileScripts.clear();
	CUseItem::TotalScripts = 0;
	std::string fileDir = ScriptVolatileDir + "/Register.xml";
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(fileDir.c_str());
	if (res.status == pugi::status_ok)
	{
		CUseItem::VolatileScripts.clear();
		pugi::xml_node flg = file.child("RegisterVolatile");
		for (pugi::xml_node curFlag = flg.first_child(); curFlag; curFlag = curFlag.next_sibling())
		{
			auto pStatus = curFlag.attribute("Status").as_bool(false);
			auto pItemID = curFlag.attribute("ItemID").as_int(0);
			auto pVolatile = curFlag.attribute("Volatile").as_int(0);
			std::string scriptDir = ScriptVolatileDir + curFlag.attribute("Script").as_string("");
			CUseItem::VolatileScripts.push_back(new CLuaVolatile(scriptDir, "OnExecute", NUM_ARGS_USEITEM, NUM_RETURN_USEITEM, pStatus, pVolatile, pItemID));

			CUseItem::TotalScripts++;
		}

		return true;
	}
	else
		return false;
}

int CUseItem::Run(int conn, char* pMsg)
{
	auto* packet = reinterpret_cast<MSG_UseItem*>(pMsg);

	sizeof(CMob);
	if ((packet->DestType == 0 && (packet->DestPos < 0 || packet->DestPos >= 16)) ||
		(packet->DestType == 1 && (packet->DestPos < 0 || packet->DestPos >= 64)) ||
		(packet->DestType == 2 && (packet->DestPos < 0 || packet->DestPos >= 128)))
		return false;

	if ((packet->SourType == 0 && (packet->SourPos < 0 || packet->SourPos >= 16)) ||
		(packet->SourType == 1 && (packet->SourPos < 0 || packet->SourPos >= 64)) ||
		(packet->SourType == 2 && (packet->SourPos < 0 || packet->SourPos >= 128)))
		return false;


	STRUCT_ITEM* src = GetItemPointer(&pMob[conn].Mob, pUser[conn].Cargo, packet->SourType, packet->SourPos);
	STRUCT_ITEM* dst = GetItemPointer(&pMob[conn].Mob, pUser[conn].Cargo, packet->DestType, packet->DestPos);

	int Vol = BASE_GetItemAbility(src, EF_VOLATILE);

	for (auto& i : CUseItem::VolatileScripts)
	{
		try
		{
			if (!i->Status)
				continue;

			if ((i->Volatile != 0 && i->Volatile == Vol) || i->ItemID == src->sIndex)
			{
				if (i->Execute(conn))
				{
					// Add AmountMinus
				}
				else
				{
					// Add SendItem on failed
				}
				return false;
			}
		}
		catch (const std::exception&)
		{
			return false;
		}

	}

	return true;
}
