#include "pch.h"
#include "CQuest.h"

std::string ScriptQuestDir = "../../Settings/Scripts/Quests"; // Register.xml

std::vector<CLuaQuest*> CQuest::QuestScripts = std::vector<CLuaQuest*>();
int CQuest::TotalScripts = 0;

constexpr auto NUM_ARGS_QUEST = 2;
constexpr auto NUM_RETURN_QUEST = 1;

bool CQuest::LoadScripts()
{
	CQuest::QuestScripts.clear();
	CQuest::TotalScripts = 0;
	std::string fileDir = ScriptQuestDir + "/Register.xml";
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(fileDir.c_str());
	if (res.status == pugi::status_ok)
	{
		CQuest::QuestScripts.clear();
		pugi::xml_node flg = file.child("RegisterQuest");
		for (pugi::xml_node curFlag = flg.first_child(); curFlag; curFlag = curFlag.next_sibling())
		{
			auto pStatus = curFlag.attribute("Status").as_bool(false);
			auto pMerchant = curFlag.attribute("Merchant").as_int(0);
			auto pLevel = curFlag.attribute("Level").as_int(0);
			auto pMobName = curFlag.attribute("MobName").as_string("");
			std::string scriptDir = ScriptQuestDir + curFlag.attribute("Script").as_string("");
			CQuest::QuestScripts.push_back(new CLuaQuest(scriptDir, "OnExecute", NUM_ARGS_QUEST, NUM_RETURN_QUEST, pStatus, pMobName, pMerchant, pLevel));

			CQuest::TotalScripts++;
		}

		std::cout << "Total CQuest Scripts: " << CQuest::TotalScripts << std::endl;
		return true;
	}
	else
		return false;
}

bool CQuest::Run(int conn, char* pMsg)
{
	if (pUser[conn].Mode == USER_PLAY)
	{
		auto p = reinterpret_cast<MSG_STANDARDPARM2*>(pMsg);
		if (p->Parm1 >= MAX_USER && p->Parm1 < MAX_MOB)
		{
			for (auto& i : CQuest::QuestScripts)
			{
				if (!i->Status)
					continue;

				if ((i->Merchant == pMob[p->Parm1].Mob.Merchant && i->Level == pMob[p->Parm1].Mob.CurrentScore.Level) || (i->MobName.length() > 1 && !i->MobName.compare(pMob[p->Parm1].Mob.MobName)))
				{
					if (i->Execute(conn, p->Parm1))
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
		}
	}

	return true;
}
