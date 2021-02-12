#include "pch.h"
#include "CHook.h"

CHook::CHook()
{
}

CHook::~CHook()
{
}

bool CHook::Initialize()
{
	return this->StartupConstants() & this->StartupNakeds();
}