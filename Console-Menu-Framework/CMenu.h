#pragma once
#include <string>
#include <vector>
#include "COption.h"

using string = std::string;

class CMenu
{
public:
	CMenu(string title);
	void Update();
	void Input();
	void AddOption(COption* option);

private:
	string m_title;
	int iSelect;
	std::vector<COption*> options;
};

