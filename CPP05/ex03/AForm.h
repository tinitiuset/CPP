#ifndef AFORM_H
#define AFORM_H

#ifndef BUREAUCRAT_H
#include "Bureaucrat.h"
#endif

#include <iostream>

class Bureaucrat;

class AForm {

private:
	std::string const _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;

public:
	AForm();

	AForm(std::string const &name, int gradeToSign, int gradeToExecute);

	AForm(AForm const &src);

	virtual ~AForm();

	AForm &operator=(AForm const &src);

	std::string const &getName() const;

	bool getSigned() const;

	int getGradeToSign() const;

	int getGradeToExecute() const;

	void beSigned(Bureaucrat const &bureaucrat);

	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

};

std::ostream &operator<<(std::ostream &o, const AForm &form);

#endif
