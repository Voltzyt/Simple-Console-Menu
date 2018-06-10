#pragma once
class CUtils
{
public:
	bool GetKeyPress(int vkey);
	void ClearConsole();
};

extern CUtils* Utils;