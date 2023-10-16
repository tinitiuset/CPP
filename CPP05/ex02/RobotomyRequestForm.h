#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#ifndef AFORM_HPP
#include "AForm.h"
#endif

class RobotomyRequestForm : public AForm {

private:
	std::string _target;

	RobotomyRequestForm();

	RobotomyRequestForm(const RobotomyRequestForm &form);

public:
	RobotomyRequestForm(const std::string target);

	RobotomyRequestForm &operator=(const RobotomyRequestForm &form);

	~RobotomyRequestForm();

	void execute(Bureaucrat const &executor) const;
};


#endif
