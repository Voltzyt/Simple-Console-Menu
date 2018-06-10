#include "CMenu.h"
#include "termcolor.h"
#include "CUtils.h"
#include <iostream>
#include <Windows.h>

CMenu::CMenu(string title)
{
	m_title = title;
	std::cout << termcolor::cyan << m_title << std::endl;
}

void CMenu::Update()
{
	Utils->ClearConsole();
	std::cout << termcolor::cyan << m_title << std::endl << std::endl;

	/* Render Our Options */

	for (auto i = options.begin(); i != options.end(); i++)
	{
		auto pos = std::distance(options.begin(), i);
		bool isSelected = (iSelect == pos);
		(*i)->Draw(isSelected);
	}
}

void CMenu::Input()
{
	if (Utils->GetKeyPress(VK_UP) && iSelect > 0)
	{
		iSelect--;
		Update();
	}

	if (Utils->GetKeyPress(VK_DOWN) && iSelect < options.size() - 1)
	{
		iSelect++;
		Update();
	}

	for (auto i = options.begin(); i != options.end(); i++)
	{
		auto pos = std::distance(options.begin(), i);
		bool isSelected = (iSelect == pos);

		if ((*i)->Input(isSelected))
			Update();
	}
	Sleep(150);
}

void CMenu::AddOption(COption* option)
{
	options.push_back(option);
	Update();
}
