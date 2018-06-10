#pragma once
#include <string>

using string = std::string;

class COption
{
public:
	virtual void Draw(bool isSelected);
	virtual bool Input(bool isSelected);
};


class CBool : public COption
{
public:
	CBool(string text, bool* setting);
	virtual void Draw(bool isSelected);
	virtual bool Input(bool isSelected);

private:
	string m_text;
	bool* m_bool;
};

class CInt : public COption
{
public:
	CInt(string text, int min, int max, int* setting);
	virtual void Draw(bool isSelected);
	virtual bool Input(bool isSelected);

private:
	string m_text;
	int* m_int;
	int m_iMin;
	int m_iMax;
};