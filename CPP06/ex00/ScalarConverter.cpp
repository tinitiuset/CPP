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
		if (std::isprint(static_cast<char>(std::stoi(input)))) {
			std::cout << static_cast<char>(std::stoi(input)) << std::endl;
		} else {
			std::cout << "Non displayable" << std::endl;
		}
	} catch (std::exception &e) {
		if (input.length() == 1 && std::isprint(input[0])) {
			std::cout << static_cast<char>(input[0]) << std::endl;
		} else {
			std::cout << "impossible" << std::endl;
		}
	}
}

void ScalarConverter::convertToInt(std::string input) {
	std::cout << "int: ";
	try {
		std::cout << static_cast<int>(std::stoi(input)) << std::endl;
	} catch (std::exception &e) {
		if (input.length() == 1 && std::isprint(input[0])) {
			std::cout << static_cast<int>(input[0]) << std::endl;
		} else {
			std::cout << "impossible" << std::endl;
		}
	}
}

void ScalarConverter::convertToFloat(std::string input) {
	std::cout << "float: ";
	try {
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(std::stof(input)) << "f" << std::endl;
	} catch (std::exception &e) {
		if (input.length() == 1 && std::isprint(input[0])) {
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(input[0])<< "f" << std::endl;
		} else {
			std::cout << "impossible" << std::endl;
		}
	}
}

void ScalarConverter::convertToDouble(std::string input) {
	std::cout << "double: ";
	try {
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(std::stod(input)) << std::endl;
	} catch (std::exception &e) {
		if (input.length() == 1 && std::isprint(input[0])) {
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(input[0]) << std::endl;
		} else {
			std::cout << "impossible" << std::endl;
		}
	}
}