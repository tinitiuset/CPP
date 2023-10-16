#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#ifndef AFORM_H
#include "AForm.h"
#endif

class PresidentialPardonForm : public AForm {

private:
	std::string _target;

	PresidentialPardonForm();

	PresidentialPardonForm(const PresidentialPardonForm &form);

public:
	PresidentialPardonForm(const std::string target);

	PresidentialPardonForm &operator=(const PresidentialPardonForm &form);

	~PresidentialPardonForm();

	void execute(Bureaucrat const &executor) const;
};

#endif
