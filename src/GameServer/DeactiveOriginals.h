#pragma once
#include <list>
struct STRUCT_DEACTIVE
{
	DWORD AddrSource;
	DWORD AddrDestiny;
	DWORD NopsSize;
};
class DeactiveOriginals
{
public:
	static bool Initialize();
private:
	static bool StartupDeactiveOriginals();
	static bool SetupDeactiveOriginals();

	static std::list< STRUCT_DEACTIVE> pDeactive;
};

