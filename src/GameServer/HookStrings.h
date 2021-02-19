#pragma once
#include <list>

struct STRUCT_STRINGS
{
	DWORD Address;
	DWORD Add;
	std::string StringReplace;
};

class HookStrings
{
public:
	static bool Initialize();
	static bool SetupStrings();
	static bool StartupStrings();

public:
	static std::list<STRUCT_STRINGS> pListString;
};

