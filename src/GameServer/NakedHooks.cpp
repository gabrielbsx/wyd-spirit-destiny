#include "pch.h"
#include "CHook.h"
#include <PEHook.h>
#include "DeactiveOriginals.h"
bool CHook::SetNakeds()
{
	if (!DeactiveOriginals::Initialize())
		return false;

	return true;
}
