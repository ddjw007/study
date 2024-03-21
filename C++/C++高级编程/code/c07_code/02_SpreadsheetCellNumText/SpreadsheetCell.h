#pragma once

#include <string>


//改良后的类，可以同时存储文本和数字
class SpreadsheetCell
{
public:
	void setValue(double inValue);
	double getValue() const;

	void setString(const std::string& inString);
	const std::string& getString() const;

private:
	std::string doubleToString(double inValue) const;
	double stringToDouble(const std::string& inString) const;

	double mValue;
	std::string mString;
};
