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
	void GetBaseAddressByName(DWORD processId, TCHAR* processName);
	bool StartBaseAddress();

private:
	CHook* HookMgr;
};

extern CMain* g_pMain;