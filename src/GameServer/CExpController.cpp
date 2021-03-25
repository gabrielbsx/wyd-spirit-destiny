#include "pch.h"
#include "CExpController.h"
#include "Native.h"

std::vector<EXP_CLASS> CExpController::vExpControl = std::vector<EXP_CLASS>();
std::vector<EXP_AREA> CExpController::vExpArea = std::vector<EXP_AREA>();

__declspec(naked) void CExpController::NKD_ExpMultiply()
{
	__asm
	{
		PUSH EDX
		PUSH EAX
		MOV ECX, DWORD PTR SS : [EBP + 0xC]
		PUSH ECX
		CALL CExpController::ProcessExpController
		ADD ESP, 0xC
		MOV DWORD PTR SS : [EBP - 0x610] , EAX
		MOV DWORD PTR SS : [EBP - 0x610 + 0x4] , EDX
		PUSH 0x056FA52
		RETN
	}
}

bool CExpController::LoadExpClass()
{
	
	try
	{
		std::ostringstream dir{ 0 };
		dir << "..\\..\\Common\\Settings\\ExpClass.xml";

		pugi::xml_document file;

		pugi::xml_parse_result res = file.load_file(dir.str().c_str());
		if (res.status == pugi::status_ok)
		{
			CExpController::vExpControl.clear();

			pugi::xml_node exp = file.child("ExpClass");

			for (pugi::xml_node nodeExp = exp.first_child(); nodeExp; nodeExp = nodeExp.next_sibling())
			{
				EXP_CLASS info{};
				info.Evolution = nodeExp.attribute("Evolution").as_int();
				info.LevelMin = nodeExp.attribute("LevelMin").as_int();

				info.LevelMax = nodeExp.attribute("LevelMax").as_int();
				info.Multiply = nodeExp.attribute("Multiply").as_int();
				CExpController::vExpControl.push_back(info);
			}
		}

		std::cout << "Total Exp Class modded: " << CExpController::vExpControl.size() << std::endl;
		return true;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		return false;
	}
}

bool CExpController::LoadExpArea()
{
	try
	{
		std::ostringstream dir{ 0 };
		dir << "..\\..\\Common\\Settings\\ExpArea.xml";

		pugi::xml_document file;

		pugi::xml_parse_result res = file.load_file(dir.str().c_str());
		if (res.status == pugi::status_ok)
		{
			CExpController::vExpArea.clear();

			pugi::xml_node exp = file.child("ExpArea");

			for (pugi::xml_node nodeExp = exp.first_child(); nodeExp; nodeExp = nodeExp.next_sibling())
			{
				EXP_AREA info{};
				info.X = nodeExp.attribute("X").as_int();
				info.Y = nodeExp.attribute("Y").as_int();

				info.xMin = nodeExp.attribute("xMin").as_int();
				info.yMin = nodeExp.attribute("yMin").as_int();

				info.xMax = nodeExp.attribute("xMax").as_int();
				info.yMax = nodeExp.attribute("yMax").as_int();
				info.Mult = nodeExp.attribute("Mult").as_int();
				CExpController::vExpArea.push_back(info);
			}
		}

		std::cout << "Total Exp Area modded: " << CExpController::vExpControl.size() << std::endl;
		return true;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		return false;
	}
}

INT64 CExpController::ProcessExpController(int conn, INT64 exp)
{
	if (conn <= 0 || conn >= MAX_USER)
		return exp;

	if(pUser[conn].Mode != USER_PLAY)
		return exp;

	auto svExp = exp;
	auto evol = GetEvolution(conn);
	auto lvl = pMob[conn].Mob.CurrentScore.Level;
	for (auto& i : CExpController::vExpControl)
	{
		if (i.Evolution == evol && lvl >= i.LevelMin && lvl <= i.LevelMax)
		{
			svExp *= i.Multiply;
			break;
		}
	}
	svExp = CExpController::ExpMultiply(conn, svExp);
	std::cout << "Exp: " << svExp << "ID:" << conn << std::endl;
	return svExp;
}

INT64 CExpController::ExpMultiply(int conn, INT64 exp)
{
	auto x = pMob[conn].PosX;
	auto y = pMob[conn].PosY;
	int areaX = x >> 7;
	int areaY = y >> 7;
	auto svExp = exp;
	for (auto& i : CExpController::vExpArea)
	{
		if ((i.X == areaX && i.Y == areaY) || (x >= i.xMin && y >= i.yMin && x <= i.xMax && y <= i.yMax))
		{
			svExp *= i.Mult;
		}
	}
	return svExp;
}
