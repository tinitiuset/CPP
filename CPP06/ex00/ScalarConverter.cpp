#include "ScalarConverter.h"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
	if (this != &rhs) {}
	return *this;
}

void ScalarConverter::convertToChar(std::string input) {
	std::cout << "char: ";
	try {
		char c = static_cast<char>(std::stoi(input));
		if (std::isprint(c)) {
			std::cout << c << std::endl;
		} else {
			std::cout << "Non displayable" << std::endl;
		}
	} catch (std::exception &e) {
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::convertToInt(std::string input) {
	std::cout << "int: ";
	try {
		int i = static_cast<int>(std::stoi(input));
		std::cout << i << std::endl;
	} catch (std::exception &e) {
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::convertToFloat(std::string input) {
	std::cout << "float: ";
	try {
		float f = static_cast<float>(std::stof(input));
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	} catch (std::exception &e) {
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::convertToDouble(std::string input) {
	std::cout << "double: ";
	try {
		double d = static_cast<double>(std::stod(input));
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	} catch (std::exception &e) {
		std::cout << "impossible" << std::endl;
	}
}