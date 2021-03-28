#include "pch.h"
#include "CExtra.h"

CExtra g_pExtra[MAX_USER]{ CExtra(), };

CExtra::CExtra()
{
	memset(&this->InGame, 0, sizeof(this->InGame));
	memset(&this->Account, 0, sizeof(this->Account));
}

CExtra::~CExtra()
{
	memset(&this->InGame, 0, sizeof(this->InGame));
	memset(&this->Account, 0, sizeof(this->Account));
}

bool CExtra::Save(SaveType type)
{
	std::ostringstream dir{ 0 };
	int rettype = this->isValid(this->Account.Info.Login[0]);
	if (rettype)
	{
		if (rettype == 1)
			dir << "..\\..\\Extra\\" << std::uppercase << this->Account.Info.Login[0] << "\\" << this->Account.Info.Login << std::nouppercase << ".xml";
		else if (rettype == 2)
			dir << "..\\..\\Extra\\" << "etc" << "\\" << this->Account.Info.Login << std::nouppercase << ".xml";
	}
	else
		return false;

	pugi::xml_document AccountDocumentBase;

	auto Account = AccountDocumentBase.append_child(pugi::node_declaration);
	Account.append_attribute("version") = "1.0";
	Account.append_attribute("encoding") = "ISO-8859-1";
	Account.append_attribute("standalone") = "yes";

	auto mainNode = AccountDocumentBase.append_child("info");

	//node Cash
	auto info = mainNode.append_child("AccountInfo");
	info.append_attribute("AccessLevel") = this->Account.Admin.AccessLevel;
	info.append_attribute("banStatus") = this->Account.Info.banStatus;
	info.append_attribute("LastMac") = this->Account.Info.LastMac;
	info.append_attribute("CurrentMac") = this->Account.Info.CurrentMac;
	info.append_attribute("IsLocked") = this->Account.Info.IsLocked;

	auto quest = mainNode.append_child("Quest");
	for (int i = 0; i < ARRAYSIZE(this->Account.QuestInfo.Quests); i++)
	{
		auto questInfo = quest.append_child("QuestInfo");
		questInfo.append_attribute("Index") = i;
		questInfo.append_attribute("Value") = this->Account.QuestInfo.Quests[i];
	}
	return AccountDocumentBase.save_file(dir.str().c_str(), PUGIXML_TEXT("  "));
}

/// <summary>
///  Carrega as informações de conta
/// </summary>
/// <param name="login">usuário</param>
/// <returns> true em caso de sucesso, false em caso de falha</returns>
bool CExtra::Load(const char* login, bool write)
{
	try
	{

		std::ostringstream dir{ 0 };
		int rettype = this->isValid(login[0]);
		if (rettype)
		{
			for (size_t i = 0; i < strlen(login); i++)
			{
				if (login[i] == '\0')
					break;

				if (!this->isValid(login[i]))
					return false;
			}
			if (rettype == 1)
				dir << "..\\..\\Extra\\" << std::uppercase << login[0] << "\\" << login << std::nouppercase << ".xml";
			else if (rettype == 2)
				dir << "..\\..\\Extra\\" << "etc" << "\\" << login << std::nouppercase << ".xml";
		}
		else
			return false;

		pugi::xml_document file;

		pugi::xml_parse_result res = file.load_file(dir.str().c_str());
		if (res.status == pugi::status_ok)
		{

			pugi::xml_node nodemain = file.child("info");
			pugi::xml_node nodeInfo = nodemain.child("AccountInfo");


			this->Account.Admin.AccessLevel = nodeInfo.attribute("AccessLevel").as_int(0);
			this->Account.Info.banStatus = nodeInfo.attribute("banStatus").as_bool(false);
			strncpy_s(this->Account.Info.LastMac, nodeInfo.attribute("LastMac").as_string(""), sizeof(this->Account.Info.LastMac));
			strncpy_s(this->Account.Info.Login, login, sizeof(this->Account.Info.Login));
			strncpy_s(this->Account.Info.LockAccount, login, sizeof(this->Account.Info.LockAccount));
			this->Account.Info.IsLocked = nodeInfo.attribute("IsLocked").as_bool(false);


			pugi::xml_node nodeQuest = nodemain.child("Quest");
			for (pugi::xml_node quest = nodeQuest.first_child(); quest; quest = quest.next_sibling())
			{

				int Index = quest.attribute("Index").as_int(0);
				if (Index >= 0 && Index < ARRAYSIZE(this->Account.QuestInfo.Quests))
				{
					this->Account.QuestInfo.Quests[Index] = quest.attribute("Value").as_int(0);
				}

			}
			return true;
		}
		else
		{
			if (write)
			{
				strncpy_s(this->Account.Info.Login, login, sizeof(this->Account.Info.Login));
				return this->Save(SaveType::NoExists);
			}
			return false;
		}
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		return false;
	}
}

int CExtra::isValid(char character)
{
	char listChar[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < ARRAYSIZE(listChar); i++)
	{
		if (listChar[i] == character)
			return 1;
	}
	char listNumber[] = "0123456789";
	for (int i = 0; i < ARRAYSIZE(listNumber); i++)
	{
		if (listNumber[i] == character)
			return 2;
	}

	return 0;
}
