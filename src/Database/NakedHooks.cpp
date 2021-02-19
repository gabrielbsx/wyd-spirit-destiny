#include "pch.h"
#include "CHook.h"
#include <PEHook.h>

bool CHook::StartupNakeds()
{

	try
	{

		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}
