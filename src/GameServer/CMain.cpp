#include "pch.h"
#include "CHook.h"
#include "CMain.h"
#include <io.h>
#include <fcntl.h>
#include <cstdio>
#include <iostream>
#include <psapi.h>
#include <tchar.h>
CMain* g_pMain = nullptr;

CMain::CMain()
{
	this->HookMgr = new CHook();
	g_pMain = this;
}

CMain::~CMain()
{
}

bool CMain::Initialize()
{

#ifdef _DEBUG
	this->StartupConsole();
	this->SafeMessage("Initializing in debug mode...");
#endif // _DEBUG

	if (!CMain::StartBaseAddress())
		return false;

#ifdef _DEBUG
	std::cout << "BaseAdress:: 0x" << std::hex << std::uppercase  << BaseAddress << std::dec << std::endl;
#endif
	return this->HookMgr->Initialize() & this->LoadFiles();
}

void CMain::SafeMessage(const char* Message, ...)
{
#ifdef _DEBUG
	char buffer[1024];
	va_list arglist;
	va_start(arglist, Message);
	vsprintf_s(buffer, Message, arglist);
	va_end(arglist);

	std::cout << this->currentDateTime() << " > ";
	std::cout << buffer << std::endl;
#endif
}


void CMain::StartupConsole()
{
	AllocConsole();
	SetConsoleTitleA("GameServer [DEBUG MODE] ");
	typedef struct { char* _ptr; int _cnt; char* _base; int _flag; int _file; int _charbuf; int _bufsiz; char* _tmpfname; } FILE_COMPLETE;
	*(FILE_COMPLETE*)stdout = *(FILE_COMPLETE*)_fdopen(_open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT), "w");
	*(FILE_COMPLETE*)stderr = *(FILE_COMPLETE*)_fdopen(_open_osfhandle((long)GetStdHandle(STD_ERROR_HANDLE), _O_TEXT), "w");
	*(FILE_COMPLETE*)stdin = *(FILE_COMPLETE*)_fdopen(_open_osfhandle((long)GetStdHandle(STD_INPUT_HANDLE), _O_TEXT), "r");
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
}

std::string CMain::currentDateTime()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	localtime_s(&tstruct, &now);
	strftime(buf, sizeof(buf), "%d-%m (%X)", &tstruct);

	return buf;
}

void CMain::GetBaseAddressByName(DWORD processId, TCHAR* processName)
{
	TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processId);

	if (NULL != hProcess)
	{
		HMODULE hMod;
		DWORD cbNeeded;

		if (EnumProcessModulesEx(hProcess, &hMod, sizeof(hMod),
			&cbNeeded, LIST_MODULES_32BIT | LIST_MODULES_64BIT))
		{
			GetModuleBaseName(hProcess, hMod, szProcessName,
				sizeof(szProcessName) / sizeof(TCHAR));
			if (!_tcsicmp(processName, szProcessName)) {
				//_tprintf(TEXT("0x%p\n"), hMod);
				BaseAddress = (DWORD)hMod + (DWORD)0xB1000;
			}
		}
	}

	CloseHandle(hProcess);
}

bool CMain::StartBaseAddress()
{
	BaseAddress = 0;

	DWORD aProcesses[1024];
	DWORD cbNeeded;
	DWORD cProcesses;

	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
		return false;

	cProcesses = cbNeeded / sizeof(DWORD);

	for (DWORD i = 0; i < cProcesses; i++) {
		GetBaseAddressByName(aProcesses[i], (TCHAR*)"TMSRVIN.exe");
	}

	return true;
}