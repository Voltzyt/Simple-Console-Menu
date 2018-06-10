#include "CUtils.h"
#include <Windows.h>

CUtils* Utils;

bool CUtils::GetKeyPress(int vkey)
{
	if ((GetAsyncKeyState(vkey) && 0x100) != 0)
		return true;
	else
		return false;
}

void CUtils::ClearConsole() /* Could make a better function for this instead of using system */
{
	system("cls");
}
