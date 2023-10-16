#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#ifndef AFORM_HPP
#include "AForm.h"
#endif

#include <fstream>

class ShrubberyCreationForm : public AForm {

private:
	std::string _target;

	ShrubberyCreationForm();

	ShrubberyCreationForm(const ShrubberyCreationForm &form);

public:
	ShrubberyCreationForm(const std::string target);

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &form);

	~ShrubberyCreationForm();

	void execute(Bureaucrat const &executor) const;
};


#endif
