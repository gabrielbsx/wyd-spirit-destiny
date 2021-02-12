#include "pch.h"
#include "CHook.h"
#include "CMain.h"
#include <io.h>
#include <fcntl.h>
#include <cstdio>
#include <iostream>

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

bool CMain::LoadFiles()
{
	return true;
}

void CMain::StartupConsole()
{
	AllocConsole();
	SetConsoleTitleA("Database [DEBUG MODE] ");
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

