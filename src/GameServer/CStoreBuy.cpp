#include "pch.h"
#include "CStoreBuy.h"

std::string ScriptBuyItemDir = "../../Settings/Scripts/BuyItem"; // Register.xml

std::vector<CLuaBuy*> CStoreBuy::BuyScripts = std::vector<CLuaBuy*>();
int CStoreBuy::TotalScripts = 0;

constexpr auto NUM_ARGS_STOREBUY = 2;
constexpr auto NUM_RETURN_STOREBUY = 1;

bool CStoreBuy::LoadScripts()
{
	CStoreBuy::BuyScripts.clear();
	CStoreBuy::TotalScripts = 0;
	std::string fileDir = ScriptBuyItemDir + "/Register.xml";
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(fileDir.c_str());
	if (res.status == pugi::status_ok)
	{
		CStoreBuy::BuyScripts.clear();
		pugi::xml_node flg = file.child("RegisterBuy");
		for (pugi::xml_node curFlag = flg.first_child(); curFlag; curFlag = curFlag.next_sibling())
		{
			auto pStatus = curFlag.attribute("Status").as_bool(false);
			STRUCT_ITEM pItemID = {};
			pItemID.sIndex = curFlag.attribute("Item").as_int(0);
			pItemID.stEffect[0].cEffect = curFlag.attribute("EF1").as_int(0);
			pItemID.stEffect[0].cValue = curFlag.attribute("EFV1").as_int(0);
			pItemID.stEffect[1].cEffect = curFlag.attribute("EF2").as_int(0);
			pItemID.stEffect[1].cValue = curFlag.attribute("EFV2").as_int(0);
			pItemID.stEffect[2].cEffect = curFlag.attribute("EF3").as_int(0);
			pItemID.stEffect[2].cValue = curFlag.attribute("EFV3").as_int(0);
			auto SellerName = curFlag.attribute("SellerName").as_string("");
			std::string scriptDir = ScriptBuyItemDir + curFlag.attribute("Script").as_string("");
			CStoreBuy::BuyScripts.push_back(new CLuaBuy(scriptDir, "OnExecute", NUM_ARGS_STOREBUY, NUM_RETURN_STOREBUY, pStatus, pItemID, SellerName));

			CStoreBuy::TotalScripts++;
		}

		std::cout << "Total CStoreBuy Scripts: " << CStoreBuy::TotalScripts << std::endl;
		return true;
	}
	else
		return false;
}

bool CStoreBuy::Run(int conn, char* pMsg)
{
	MSG_ReqBuy* p = reinterpret_cast<MSG_ReqBuy*>(pMob);

	if (p->Pos < 0 || p->Pos > MAX_CARRY - 4)
		return false;

	if (p->TargetID > MAX_USER && p->TargetID < MAX_MOB && pUser[conn].Mode == USER_PLAY)
	{
		auto TargetID = p->TargetID;
		if (pMob[TargetID].Mob.Merchant == 1)
		{
			for (auto& i : CStoreBuy::BuyScripts)
			{
				if (!i->Status)
					continue;

				if ((i->SellerName.length() > 1 && !i->SellerName.compare(pMob[TargetID].Mob.MobName)) || (!memcmp(&i->Item, &pMob[TargetID].Mob.Carry[p->Pos], sizeof(STRUCT_ITEM))))
				{
					if (i->Execute(conn, TargetID))
					{
						// AddLog
					}
					else
					{
						// AddLog
					}
					return false;
				}
			}
			return true;
		}
		return false;
	}
	return true;

}
