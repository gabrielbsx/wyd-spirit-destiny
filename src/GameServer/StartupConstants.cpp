#include "pch.h"
#include "CHook.h"
#include <PEHook.h>
#include "HookStrings.h"
#include "GlobalPointer.h"


std::list<SETUP_CONSTANTS> CHook::pConstants = std::list<SETUP_CONSTANTS>();

bool CHook::SetConstants()
{
	if (!CHook::StartupConstants())
		return false;

	if (!HookStrings::Initialize())
		return false;

	if (!GlobalPointer::Initialize())
		return false;



	return true;
}

bool CHook::StartupConstants()
{
	try
	{
		std::ostringstream dir{ 0 };
		dir << "../../Settings/ReplaceConstants" << ".xml";

		pugi::xml_document file;

		pugi::xml_parse_result res = file.load_file(dir.str().c_str());
		if (res.status == pugi::status_ok)
		{
			CHook::pConstants.clear();
			pugi::xml_node flg = file.child("Constants");
			for (pugi::xml_node curFlag = flg.first_child(); curFlag; curFlag = curFlag.next_sibling())
			{
				SETUP_CONSTANTS consType{};
				consType.Address = curFlag.attribute("Address").as_uint(0x0);
				consType.Add = curFlag.attribute("Add").as_uint(0x0);
				consType.changeType = curFlag.attribute("Type").as_string("");

				if (!consType.changeType.compare("BYTE"))
				{
					consType.ValueByte = static_cast<BYTE>(curFlag.attribute("Value").as_uint(0x0));
				}
				else if (!consType.changeType.compare("SHORT"))
				{
					consType.ValueShort = static_cast<short>(curFlag.attribute("Value").as_uint(0x0));
				}
				else if (!consType.changeType.compare("DWORD"))
				{
					consType.ValueDword = static_cast<DWORD>(curFlag.attribute("Value").as_uint(0x0));
				}
				else if (!consType.changeType.compare("FLOAT"))
				{
					consType.ValueFloat = static_cast<float>(curFlag.attribute("Value").as_float(0.0f));
				}
				else if (!consType.changeType.compare("DOUBLE"))
				{
					consType.ValueDouble = static_cast<double>(curFlag.attribute("Value").as_double(0.0));
				}
				else if (!consType.changeType.compare("INT64"))
				{
					consType.ValueInt64 = static_cast<unsigned long long>(curFlag.attribute("Value").as_ullong(0));
				}
				else if (!consType.changeType.compare("NOP"))
				{
					consType.NopSize = static_cast<DWORD>(curFlag.attribute("Value").as_uint(0));
				}
				else
				{
					std::cout << "Invalid Type: " << consType.changeType.c_str() << std::endl;
					continue;
				}
				CHook::pConstants.push_back(consType);
			}
			return CHook::SetupConstants();
		}
		return false;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

bool CHook::SetupConstants()
{
	try
	{
		for (auto& i : CHook::pConstants)
		{
			if (!i.changeType.compare("BYTE"))
			{
				PEHook::SETBYTE(i.ValueByte, BaseAddress + i.Address + i.Add);
			}
			else if (!i.changeType.compare("SHORT"))
			{
				PEHook::SETWORD(i.ValueShort, BaseAddress + i.Address + i.Add);
			}
			else if (!i.changeType.compare("DWORD"))
			{
				PEHook::SETDWORD(i.ValueDword, BaseAddress + i.Address + i.Add);
			}
			else if (!i.changeType.compare("FLOAT"))
			{
				PEHook::SETFLOAT(i.ValueFloat, BaseAddress + i.Address + i.Add);
			}
			else if (!i.changeType.compare("DOUBLE"))
			{
				PEHook::SETDOUBLE(i.ValueDouble, BaseAddress + i.Address + i.Add);
			}
			else if (!i.changeType.compare("INT64"))
			{

				PEHook::SETLLONG(i.ValueInt64, BaseAddress + i.Address + i.Add);
			}
			else if (!i.changeType.compare("NOP"))
			{
				PEHook::FillWithNop(BaseAddress + i.Address + i.Add, i.NopSize);
			}
		}
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}