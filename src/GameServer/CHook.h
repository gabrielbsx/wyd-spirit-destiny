#pragma once
#include <list>
struct SETUP_CONSTANTS
{
	DWORD Address;
	DWORD Add;
	std::string changeType;

	BYTE ValueByte;
	short ValueShort;
	DWORD ValueDword;
	float ValueFloat;
	double ValueDouble;
	long long ValueInt64;
	DWORD NopSize;
};
class CHook
{
public:
	CHook();
	~CHook();

	bool Initialize();

private:
	bool SetConstants();
	bool SetNakeds();

	bool StartupConstants();
	bool SetupConstants();

	static std::list<SETUP_CONSTANTS> pConstants;
};
