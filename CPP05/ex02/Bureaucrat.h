#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

#ifndef FORM_H
#include "AForm.h"
#endif

class AForm;

class Bureaucrat {

private:
	std::string const _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &src);

	std::string const &getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(AForm &form) const;
	void executeForm(AForm const &form) const;

	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif