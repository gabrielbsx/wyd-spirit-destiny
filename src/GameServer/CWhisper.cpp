#include "pch.h"
#include "CWhisper.h"
#include "CMain.h"
#include "Native.h"
#include "CUseItem.h"
#include "CMobKilled.h"
#include "CQuest.h"
#include "CStoreBuy.h"
#include "CExpController.h"
#include "CDropController.h"
#include "CExtra.h"

std::string ScriptCommandDir = "../../Settings/Scripts/Commands"; // Register.xml

std::vector<CLuaWishper*> CWhisper::CommandScripts = std::vector<CLuaWishper*>();
int CWhisper::TotalScripts = 0;

constexpr auto NUM_ARGS_WHISPER = 2;
constexpr auto NUM_RETURN_WHISPER = 1;

bool CWhisper::LoadScripts()
{
	CWhisper::CommandScripts.clear();
	CWhisper::TotalScripts = 0;
	std::string fileDir = ScriptCommandDir + "/Register.xml";
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(fileDir.c_str());
	if (res.status == pugi::status_ok)
	{
		CWhisper::CommandScripts.clear();
		pugi::xml_node flg = file.child("RegisterCommand");
		for (pugi::xml_node curFlag = flg.first_child(); curFlag; curFlag = curFlag.next_sibling())
		{
			auto pStatus = curFlag.attribute("Status").as_bool(false);
			auto Level = curFlag.attribute("Level").as_int(0);
			auto Command = curFlag.attribute("Command").as_string("");
			std::string scriptDir = ScriptCommandDir + curFlag.attribute("Script").as_string("");
			CWhisper::CommandScripts.push_back(new CLuaWishper(scriptDir, "OnExecute", NUM_ARGS_WHISPER, NUM_RETURN_WHISPER, pStatus, Command, Level));

			CWhisper::TotalScripts++;
		}
		std::cout << "Total CWhisper Scripts: " << CWhisper::TotalScripts << std::endl;
		return true;
	}
	else
		return false;
}


bool CWhisper::Run(int conn, char* pMsg)
{
	MSG_MessageWhisper* p = reinterpret_cast<MSG_MessageWhisper*>(pMsg);

	p->MobName[15] = 0;
	p->MobName[14] = 0;
	p->String[127] = 0;
	p->String[126] = 0;

	if (pUser[conn].Mode == USER_PLAY)
	{
		for (auto& i : CWhisper::CommandScripts)
		{
			if (!i->Status)
				continue;

			if (i->Level != 0 && g_pExtra[conn].Account.Admin.AccessLevel < i->Level)
				continue;

			if (!i->Command.compare(p->MobName))
			{
				if (i->Execute(conn, p->String))
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

		if (g_pExtra[conn].InGame.Admin.isAdmin && g_pExtra[conn].Account.Admin.AccessLevel >= 10 && !strcmp(p->MobName, "load"))
		{
			if (!strcmp(p->String, "all")) !g_pMain->LoadFiles() ? SendClientMessage(conn, "+FAILED ON LOAD ALL SCRIPTS") : SendClientMessage(conn, "+SUCESS ON LOAD ALL SCRIPTS");
			else if (!strcmp(p->String, "commands")) !CWhisper::LoadScripts() ? SendClientMessage(conn, "+FAILED ON LOAD COMMANDS") : SendClientMessage(conn, "+SUCESS ON LOAD COMMANDS");
			else if (!strcmp(p->String, "quests")) !CQuest::LoadScripts() ? SendClientMessage(conn, "+FAILED ON LOAD QUESTS") : SendClientMessage(conn, "+SUCESS ON LOAD QUESTS");
			else if (!strcmp(p->String, "volatiles")) !CUseItem::LoadScripts() ? SendClientMessage(conn, "+FAILED ON LOAD VOLATILES") : SendClientMessage(conn, "+SUCESS ON LOAD VOLATILES");
			else if (!strcmp(p->String, "mobkilled")) !CMobKilled::LoadScripts() ? SendClientMessage(conn, "+FAILED ON LOAD MOBKILLED") : SendClientMessage(conn, "+SUCESS ON LOAD MOBKILLED");
			else if (!strcmp(p->String, "storebuy")) !CStoreBuy::LoadScripts() ? SendClientMessage(conn, "+FAILED ON LOAD STORE BUY") : SendClientMessage(conn, "+SUCESS ON LOAD STORE BUY");
			else if (!strcmp(p->String, "hooks")) !g_pMain->LoadHooks() ? SendClientMessage(conn, "+FAILED ON LOAD HOOKS") : SendClientMessage(conn, "+SUCESS ON LOAD HOOKS");
			else if (!strcmp(p->String, "exparea")) !CExpController::LoadExpArea() ? SendClientMessage(conn, "+FAILED ON LOAD EXP AREA") : SendClientMessage(conn, "+SUCESS ON LOAD EXPAREA");
			else if (!strcmp(p->String, "expclass")) !CExpController::LoadExpClass() ? SendClientMessage(conn, "+FAILED ON LOAD EXP CLASS") : SendClientMessage(conn, "+SUCESS ON LOAD CLASS");
			else if (!strcmp(p->String, "drop")) !CDropController::Initialize() ? SendClientMessage(conn, "+FAILED ON LOAD DROP") : SendClientMessage(conn, "+SUCESS ON DROP");
			else SendClientMessage(conn, "Comando secunário inválido!");

			return false;
		}


	}

	return true;
}
