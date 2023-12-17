#include <iostream>

#include <vector>
#include <array>
#include <list>

#include "easyfind.h"

int main(void) {

	std::cout << "Vector:" << std::endl;
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	try {
		std::cout << "Looking for 3:" << std::endl;
		easyfind(v, 3);
		std::cout << "Looking for 5:" << std::endl;
		easyfind(v, 5);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "Array:" << std::endl;
	std::array<int, 4> a = {1, 2, 3, 4};
	try {
		std::cout << "Looking for 3:" << std::endl;
		easyfind(a, 3);
		std::cout << "Looking for 5:" << std::endl;
		easyfind(a, 5);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "List:" << std::endl;
	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	try {
		std::cout << "Looking for 3:" << std::endl;
		easyfind(l, 3);
		std::cout << "Looking for 5:" << std::endl;
		easyfind(l, 5);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}