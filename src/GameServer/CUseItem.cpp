#include "pch.h"
#include "CUseItem.h"

std::string ScriptVolatileDir = "../../Settings/Scripts/Volatiles/"; // Register.xml
std::vector<CLuaScripts> CUseItem::VolatileScripts = std::vector<CLuaScripts>();
bool CUseItem::LoadScripts()
{
	CUseItem::VolatileScripts.clear();
	/// TODO:
	/// Load XML File
	/// Load Script File
	/// Test register script
	/// Create Steatment for local variables
	/// 

	return false;
}

bool CUseItem::SetupFunctions()
{
	/// TODO:
	/// Need imple all functions native here.
	/// Need pass CMob and CUser class to function or create any function
	/// Need implement how to pass packet info to pointer
	return false;
}

int CUseItem::ProcessMessages(int conn, char* pMsg)
{
	return 0;
}
