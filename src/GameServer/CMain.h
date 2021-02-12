#pragma once
class CHook;
class CMain
{
public:
	CMain();
	~CMain();

	bool Initialize();
private:
	bool LoadFiles();


private:
	CHook* HookMgr;
};

extern CMain* g_pMain;
