#include "pch.h"
#include "LuaExport.h"
#include "GlobalPointer.h"
#include "Native.h"
#include "LuaMob.h"
#include "LuaSend.h"
#include "LuaGet.h"
#include "LuaUser.h"
#include "LuaItem.h"
#include "LuaPosition.h"
#include "LuaExtra.h"
void LuaExport::InitalizeExports(lua_State* L)
{
	try
	{
		LuaMob::Initialize_MetaTable(L);
		LuaUser::Initialize_MetaTable(L);
		LuaExtra::Initialize_MetaTable(L);
		LuaItem::Initialize_MetaTable(L);
		LuaSend::Initialize_MetaTable(L);
		LuaGet::Initialize_MetaTable(L);
		LuaPosition::Initialize_MetaTable(L);

	}
	catch (const std::exception& ex)
	{
#ifdef _DEBUG
		std::cout << "Failed on register functions Error:  " << ex.what() << std::endl;
#endif
	}
}
