#pragma once

class SpreadsheetCell
{
public:
	void setValue(double inValue);
	double getValue() const;	//静态声明

private:
	double mValue;
};
