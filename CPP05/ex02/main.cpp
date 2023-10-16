#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int main(void) {

	Bureaucrat b1("b1", 1);
	Bureaucrat b2("b2", 150);

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;

	ShrubberyCreationForm f1("home");
	b1.signForm(f1);
	b1.executeForm(f1);

	RobotomyRequestForm f2("bender");
	b1.signForm(f2);
	b2.executeForm(f2);

	PresidentialPardonForm f3("zafod");
	b2.signForm(f3);
	b1.executeForm(f3);

	return 0;
}