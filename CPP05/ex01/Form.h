#ifndef FORM_H
#define FORM_H

#include <iostream>

#ifndef BUREAUCRAT_H
#include "Bureaucrat.h"
#endif

class Bureaucrat;

class Form {

private:
	std::string const _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;

public:
	Form();
	Form(std::string const &name, int gradeToSign, int gradeToExecute);
	Form(Form const &src);
	~Form();

	Form &operator=(Form const &src);

	std::string const &getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(Bureaucrat const &bureaucrat);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

};

std::ostream	&operator<<(std::ostream &o, const Form &form);

#endif
