#include "pch.h"
#include "CHook.h"

CHook::CHook()
{
}

CHook::~CHook()
{
	delete[] this;
}

bool CHook::Initialize()
{
	return this->StartupConstants() & this->StartupNakeds();
}
