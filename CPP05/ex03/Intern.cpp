#include "Intern.h"

Intern::Intern() {}

Intern::Intern(const Intern &intern) {
	*this = intern;
}

Intern &Intern::operator=(const Intern &intern) {
	if (this != &intern) {}
	return *this;
}

Intern::~Intern() {}

AForm *Intern::createPresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target) {
	AForm *form = NULL;
	std::string formNames[3] = {"Presidential pardon", "Robotomy request", "Shrubbery creation"};
	AForm *(*p[3])(std::string) = {createPresidentialPardonForm, createRobotomyRequestForm, createShrubberyCreationForm};
	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			form = p[i](target);
			std::cout << "Intern creates " << formName << std::endl;
			return form;
		}
	}
	throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}