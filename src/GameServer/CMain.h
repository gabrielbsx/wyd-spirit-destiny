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
	bool LoadFiles();
	bool LoadHooks();
private:
	void StartupConsole();
	std::string currentDateTime();
	void GetBaseAddressByName(DWORD processId, TCHAR* processName);
	bool StartBaseAddress();

	CHook* HookMgr;
};

extern CMain* g_pMain;