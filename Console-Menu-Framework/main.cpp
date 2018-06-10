#include "CUtils.h"
#include "CMenu.h"
#include <windows.h>

bool bTest;
int iTest;

int main()
{
	CMenu Menu = CMenu("Voltz' CLI Menu Framework"); // Create menu 
	Menu.AddOption(new CBool("Example CBool", &bTest)); // Create Bool Menu Item | Params: Text, &bSetting
	Menu.AddOption(new CInt("Example CInt", 0, 5, &iTest)); // Create Integer Menu Item | Params: Text, min, max, &iSetting

	for(;;)
	{
		Menu.Input(); // Constantly check for input
		Sleep(1); // :)
	}
    return 0;
}

