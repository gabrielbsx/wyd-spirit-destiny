#pragma once
#include <string>
class CHook;
class CMain
{
public:
	 CMain();
	 ~CMain();

	bool Initialize();
	void SafeMessage(const char* Message, ...);
private:
	bool LoadFiles();
	void StartupConsole();
	std::string currentDateTime();
private:
	CHook* HookMgr;
};

extern CMain* g_pMain;
