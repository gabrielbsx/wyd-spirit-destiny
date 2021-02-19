#include "pch.h"
#include "DeactiveOriginals.h"
#include <PEHook.h>

std::list<STRUCT_DEACTIVE> DeactiveOriginals::pDeactive = std::list<STRUCT_DEACTIVE>();

bool DeactiveOriginals::Initialize()
{
	try
	{
		if (!StartupDeactiveOriginals())
			return false;

		if (!SetupDeactiveOriginals())
			return false;

		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

bool DeactiveOriginals::StartupDeactiveOriginals()
{
	try
	{

		std::ostringstream dir{ 0 };
		dir << "../../Settings/ReplaceConstants" << ".xml";

		pugi::xml_document file;

		pugi::xml_parse_result res = file.load_file(dir.str().c_str());
		if (res.status == pugi::status_ok)
		{
			DeactiveOriginals::pDeactive.clear();
			pugi::xml_node flg = file.child("Deactive");
			for (pugi::xml_node curFlag = flg.first_child(); curFlag; curFlag = curFlag.next_sibling())
			{
				STRUCT_DEACTIVE deactiveType{};
				deactiveType.AddrSource = curFlag.attribute("AddrSource").as_uint(0x0);
				deactiveType.AddrDestiny = curFlag.attribute("AddrDestiny").as_uint(0x0);
				deactiveType.NopsSize = curFlag.attribute("NopsSize").as_uint(0x0);
				DeactiveOriginals::pDeactive.push_back(deactiveType);
			}
			return true;
		}
		return false;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

bool DeactiveOriginals::SetupDeactiveOriginals()
{
	try
	{
		for (auto& i : DeactiveOriginals::pDeactive)
		{
			PEHook::JMP_NEAR(BaseAddress + i.AddrSource,(void*)(BaseAddress + i.AddrDestiny), i.NopsSize);
		}
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}
