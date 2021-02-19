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
	return this->SetConstants() & this->SetNakeds();
}
