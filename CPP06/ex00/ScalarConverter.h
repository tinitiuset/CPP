#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <iomanip>

class ScalarConverter{
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &rhs);

public:
	static void convertToChar(std::string);
	static void convertToInt(std::string);
	static void convertToFloat(std::string);
	static void convertToDouble(std::string);

};

#endif