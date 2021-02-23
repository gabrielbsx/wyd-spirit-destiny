#pragma once

class CUseItem
{
public:
	CUseItem() {};
	~CUseItem() {};

	static bool LoadScripts();
	static bool SetupFunctions();
	static int ProcessMessages(int conn, char* pMsg);

public:
	static std::vector<CLuaScripts> VolatileScripts;
};

