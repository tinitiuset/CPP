#include "ScalarConverter.h"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}

	ScalarConverter converter;
	converter.convertToChar(argv[1]);
	converter.convertToInt(argv[1]);
	converter.convertToFloat(argv[1]);
	converter.convertToDouble(argv[1]);
	return 0;
}