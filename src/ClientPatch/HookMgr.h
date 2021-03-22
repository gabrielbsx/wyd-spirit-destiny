#pragma once
class HookMgr
{
public:
	static void ChangeWindowName();
	static void FixAutoTradeName();
	static void SetVersion(int version);
	static void SmallPatches();
	static bool InitializeConstants();
	static bool InitializeNakeds();
};

