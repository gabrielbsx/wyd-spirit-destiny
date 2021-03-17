#pragma once
#include "pch.h"
#include <PEHook.h>
#include "HookStrings.h"

std::list<STRUCT_STRINGS> HookStrings::pListString = std::list<STRUCT_STRINGS>();

bool HookStrings::Initialize()
{
	return HookStrings::SetupStrings() & HookStrings::StartupStrings();
}
bool HookStrings::SetupStrings()
{
	try
	{
		std::ostringstream dir{ 0 };
		dir << "../../Settings/ReplaceStrings" << ".xml";

		pugi::xml_document file;

		pugi::xml_parse_result res = file.load_file(dir.str().c_str());
		if (res.status == pugi::status_ok)
		{
			HookStrings::pListString.clear();
			pugi::xml_node flg = file.child("Flags");
			for (pugi::xml_node curFlag = flg.first_child(); curFlag; curFlag = curFlag.next_sibling())
			{
				STRUCT_STRINGS stringVal{};
				stringVal.Address = curFlag.attribute("Address").as_uint(0x0);
				stringVal.Add = curFlag.attribute("Add").as_uint(0x0);
				stringVal.StringReplace = curFlag.attribute("Value").as_string("");

				HookStrings::pListString.push_back(stringVal);
			}
			return true;
		}
		return false;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;

	}
	return false;
}

bool HookStrings::StartupStrings()
{
	try
	{
		for (auto& i : HookStrings::pListString)
		{
			PEHook::SETDWORD((DWORD)i.StringReplace.c_str(),BaseAddress +  i.Address + i.Add);
		}
		std::cout << "Total strings changed: " << HookStrings::pListString.size() << std::endl;

		return true;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;

		return false;
	}
}
