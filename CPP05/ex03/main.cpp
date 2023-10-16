#include "Intern.h"

int main(void) {

	Intern i1;

	try {
		AForm *f1 = i1.makeForm("Shrubbery creation", "home");
		delete f1;
		AForm *f2 = i1.makeForm("Robotomy request", "bender");
		delete f2;
		AForm *f3 = i1.makeForm("Presidential pardon", "zafod");
		delete f3;
		AForm *f4 = i1.makeForm("Unknown form", "unknown");
		delete f4;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}