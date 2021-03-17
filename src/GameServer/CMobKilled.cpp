#include "pch.h"
#include "CMobKilled.h"

__declspec(naked) void CMobKilled::NKD_Modify()
{
	static DWORD firstPush = (DWORD)BaseAddress + 0xBE4DD;
	static DWORD secndPush = (DWORD)BaseAddress + 0xBE2B2;
	static DWORD thirdPush = (DWORD)BaseAddress + 0xBE2C2;

	__asm
	{
		PUSH DWORD PTR SS : [EBP + 0xC] // Killer
		PUSH DWORD PTR SS : [EBP + 0x8] // Killed
		PUSH DWORD PTR SS : [EBP - 0x5AC] // GenerateIndex
		CALL CMobKilled::Execute
		ADD ESP, 12

		TEST AL, AL // Se for false, vai pra próxima comparação
		JE lblContinueExec
		PUSH firstPush
		RETN

		lblContinueExec :
		CMP DWORD PTR SS : [EBP - 0x5AC] , 0x10E
			JL lblNext
			PUSH secndPush
			RETN

			lblNext :
		PUSH thirdPush
			RETN
	}

}

std::string ScriptKilledDir = "../../Settings/Scripts/MobKilled";

std::vector<CLuaMobKilled*> CMobKilled::MobKilledScripts = std::vector<CLuaMobKilled*>();
int CMobKilled::TotalScripts = 0;

constexpr auto NUM_ARGS_MOBKILLED = 2;
constexpr auto NUM_RETURN_MOBKILLED = 1;

bool CMobKilled::LoadScripts()
{
	CMobKilled::MobKilledScripts.clear();
	CMobKilled::TotalScripts = 0;
	std::string fileDir = ScriptKilledDir + "/Register.xml";
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(fileDir.c_str());
	if (res.status == pugi::status_ok)
	{
		CMobKilled::MobKilledScripts.clear();
		pugi::xml_node flg = file.child("RegisterKilled");
		for (pugi::xml_node curFlag = flg.first_child(); curFlag; curFlag = curFlag.next_sibling())
		{
			auto pStatus = curFlag.attribute("Status").as_bool(false);
			auto pGen = curFlag.attribute("GenerID").as_int(0);
			auto pMobName = curFlag.attribute("MobName").as_string("");
			std::string scriptDir = ScriptKilledDir + curFlag.attribute("Script").as_string("");
			CMobKilled::MobKilledScripts.push_back(new CLuaMobKilled(scriptDir, "OnExecute", NUM_ARGS_MOBKILLED, NUM_RETURN_MOBKILLED, pStatus, pMobName, pGen));

			CMobKilled::TotalScripts++;
		}
		std::cout << "Total MobKilled Scripts: " << CMobKilled::TotalScripts << std::endl;
		return true;
	}
	else
		return false;
}

int CMobKilled::Execute(int killer, int killed, int posX, int posY)
{


	auto genID = pMob[killed].GenerateIndex;
	auto tmpKiller = killer >= MAX_USER ? pMob[killer].PartyLeader : killer;
	if (tmpKiller == 0 || tmpKiller >= MAX_USER || killed < MAX_USER)
		return true;

	for (auto& i : CMobKilled::MobKilledScripts)
	{

		if (!i->Status)
			continue;

		if (i->GenerID == genID || i->MobName.length() > 1 && i->MobName.compare(pMob[killed].Mob.MobName))
		{
			if (killer >= MAX_USER)
			{
				if (i->Execute(killer, killed))
				{

				}
				else
				{

				}
			}
		}
	}

	return true;
}
