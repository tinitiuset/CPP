#include "ScalarConverter.h"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}

	ScalarConverter::convertToChar(argv[1]);
	ScalarConverter::convertToInt(argv[1]);
	ScalarConverter::convertToFloat(argv[1]);
	ScalarConverter::convertToDouble(argv[1]);
	return 0;
}