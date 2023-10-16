#ifndef INTERN_H
#define INTERN_H

#ifndef FORM_H
#include "AForm.h"
#endif

#ifndef PRESIDENTIALPARDONFORM_H
#include "PresidentialPardonForm.h"
#endif

#ifndef ROBOTOMYREQUESTFORM_HPP
#include "RobotomyRequestForm.h"
#endif

#ifndef SHRUBBERYCREATIONFORM_HPP
#include "ShrubberyCreationForm.h"
#endif

#include <iostream>

class Intern {

public:
	Intern();

	Intern(const Intern &intern);

	Intern &operator=(const Intern &intern);

	~Intern();

	AForm *makeForm(std::string formName, std::string target);

	static AForm *createPresidentialPardonForm(std::string target);

	static AForm *createRobotomyRequestForm(std::string target);

	static AForm *createShrubberyCreationForm(std::string target);

	class FormNotFoundException : public std::exception {
	public:
		const char *what() const throw();
	};

};

#endif
