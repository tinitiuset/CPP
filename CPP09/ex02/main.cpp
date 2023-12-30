#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char **argv) {

	if (argc < 2) {
		std::cout << "Error: invalid number of arguments" << std::endl;
		return 1;
	}

	try {
		PmergeMe pmergeme(argv);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}