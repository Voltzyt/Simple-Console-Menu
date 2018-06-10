#include "COption.h"
#include "CUtils.h"
#include "termcolor.h"
#include <iostream>

/* BASE */
void COption::Draw(bool isSelected) {}
bool COption::Input(bool isSelected) { return false; }



/* Boolean Toggle */
CBool::CBool(string text, bool * setting)
{
	m_text = text;
	m_bool = setting;
}

void CBool::Draw(bool isSelected)
{
		std::cout << (isSelected ? termcolor::green : termcolor::white) << m_text << ": " << (*m_bool ? "ON" : "OFF") << std::endl;
}

bool CBool::Input(bool isSelected)
{
	if (isSelected)
	{
		if (Utils->GetKeyPress(VK_RIGHT) || Utils->GetKeyPress(VK_LEFT))
		{
			*m_bool = !(*m_bool);
			return true;
		}
	}
	return false;
}


/* Int */

CInt::CInt(string text, int min, int max, int * setting)
{
	m_text = text;
	m_int = setting;
	m_iMin = min;
	m_iMax = max;
}

void CInt::Draw(bool isSelected)
{
	std::cout << (isSelected ? termcolor::green : termcolor::white) << m_text << ": " << "<" << *m_int << ">" << std::endl;
}

bool CInt::Input(bool isSelected)
{
	if (isSelected)
	{
		if (Utils->GetKeyPress(VK_RIGHT) && *m_int < m_iMax)
		{
			*m_int += 1;
			return true;
		}

		if (Utils->GetKeyPress(VK_LEFT) && *m_int > m_iMin)
		{
			*m_int -= 1;
			return true;
		}
	}
	return false;
}
