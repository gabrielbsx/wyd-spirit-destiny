#pragma once
#include <string>
class CHook;

struct st_BanMacList
{
	char CurrentMac[18];
};
class CMain
{
public:
	CMain();
	~CMain();

	bool Initialize();
	void SafeMessage(const char* Message, ...);
	bool LoadFiles();
	bool LoadHooks();
	bool Maitence;
	std::vector<st_BanMacList> BanMac;
private:
	void StartupConsole();
	std::string currentDateTime();
	void GetBaseAddressByName(DWORD processId, TCHAR* processName);
	bool StartBaseAddress();
	


	CHook* HookMgr;
};

extern CMain* g_pMain;