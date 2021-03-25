#include "pch.h"
#include "CDropController.h"

std::vector<DROP_AREA> CDropController::vDropArea = std::vector<DROP_AREA>();
std::vector<short> CDropController::vBlockDrop = std::vector<short>();

bool CDropController::Initialize()
{
	return CDropController::LoadBlockDrop() & CDropController::LoadDropArea();
}

__declspec(naked) void CDropController::NKD_BlockDrop()
{
	__asm
	{
		MOVSX ECX, WORD PTR DS : [EAX]
		PUSH ECX
		CALL CDropController::ProcessBlockDrop
		ADD ESP, 0x4
		CMP EAX, 0
		JE AbortExec
		PUSH 0x0571308
		RETN
		AbortExec :
		PUSH 0x0571319
			RETN
	}
}

__declspec(naked) void CDropController::NKD_DropArea()
{
	__asm
	{
		MOV EAX, DWORD PTR SS : [EBP - 0x95C]
		PUSH EAX
		MOV EAX, DWORD PTR SS : [EBP + 0xC]
		PUSH EAX
		CALL CDropController::DropMultiply
		ADD ESP, 0x8
		MOV DWORD PTR SS : [EBP - 0x95C] , EAX
		PUSH 0x05712BC
		RETN
	}
}
bool CDropController::LoadDropArea()
{
	try
	{
		std::ostringstream dir{ 0 };
		dir << "..\\..\\Common\\Settings\\DropArea.xml";

		pugi::xml_document file;

		pugi::xml_parse_result res = file.load_file(dir.str().c_str());
		if (res.status == pugi::status_ok)
		{
			CDropController::vDropArea.clear();

			pugi::xml_node exp = file.child("DropArea");

			for (pugi::xml_node nodeExp = exp.first_child(); nodeExp; nodeExp = nodeExp.next_sibling())
			{
				DROP_AREA info{};
				info.X = nodeExp.attribute("X").as_int();
				info.Y = nodeExp.attribute("Y").as_int();

				info.xMin = nodeExp.attribute("XMin").as_int();
				info.yMin = nodeExp.attribute("YMin").as_int();

				info.xMax = nodeExp.attribute("XMax").as_int();
				info.yMax = nodeExp.attribute("YMax").as_int();
				info.Bonus = nodeExp.attribute("Bonus").as_int();
				CDropController::vDropArea.push_back(info);
			}
		}

		std::cout << "Total Drop Area modded: " << CDropController::vDropArea.size() << std::endl;
		return true;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		return false;
	}
}
bool CDropController::LoadBlockDrop()
{
	std::ifstream file("..\\..\\Common\\Settings\\BlockDrop.txt");

	if (file.is_open())
	{
		CDropController::vBlockDrop.clear();

		short itemId = 0;

		while (file >> itemId)
			CDropController::vBlockDrop.push_back(itemId);

		file.close();
		return true;
	}
	return false;
}
//5712FB
int CDropController::ProcessBlockDrop(short itemID)
{
	if (itemID <= 0)
		return false;
	for (auto& i : CDropController::vBlockDrop)
	{
		if (itemID == i)
			return false;
	}
	return itemID;
}

int CDropController::DropMultiply(int conn, int rate)
{
	auto x = pMob[conn].PosX;
	auto y = pMob[conn].PosY;
	int areaX = x >> 7;
	int areaY = y >> 7;
	auto svRate = rate;

	for (auto& i : CDropController::vDropArea)
	{
		if ((i.X == areaX && i.Y == areaY) || (x >= i.xMin && y >= i.yMin && x <= i.xMax && y <= i.yMax))
		{
			if (svRate <= 0)
				return 0;

			svRate = svRate / 100 * i.Bonus;
		}
	}
	if (svRate <= 0)
		return 0;
	else
		return rand() % svRate;
}
