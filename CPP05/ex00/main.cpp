#include "Bureaucrat.h"

int main(void) {

	Bureaucrat b1("b1", 1);

	std::cout << b1 << std::endl;
	try {
		b1.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << b1 << std::endl;
	try {
		b1.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << b1 << std::endl;

	Bureaucrat b2("b2", 150);

	std::cout << b2 << std::endl;
	try {
		b2.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << b2 << std::endl;
	try {
		b2.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << b2 << std::endl;
	return 0;
}