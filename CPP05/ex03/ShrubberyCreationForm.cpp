#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery creation", 145, 137), _target("unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) : AForm(form), _target(form._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form) {
	if (this != &form) {
		_target = form._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	AForm::execute(executor);
	std::ofstream file(_target + "_shrubbery");
	file << "         _-_                     _-_                 _-_                    _-_                  _-_          " << std::endl;
	file << "      /~~   ~~\\              /~~   ~~\\          /~~   ~~\\             /~~   ~~\\           /~~   ~~\\      " << std::endl;
	file << "    /~~         ~~\\        /~~         ~~\\    /~~         ~~\\       /~~         ~~\\     /~~         ~~\\  " << std::endl;
	file << "   {               }       {               }   {               }      {               }    {               }  " << std::endl;
	file << "    \\  _-     -_  /        \\  _-     -_  /    \\  _-     -_  /       \\  _-     -_  /     \\  _-     -_  /  " << std::endl;
	file << "      ~  \\\\ //  ~           ~  \\\\ //  ~       ~  \\\\ //             ~  \\\\ //  ~        ~  \\\\ //      " << std::endl;
	file << "   _- -   | | _  _         _- -   | | _- _     _- -   | | _- _        _- -   | |    _         -   | | _- _    " << std::endl;
	file << "       -  | |   -_           _ -  | |    _       _ -  | |   -_          _ -  | |   -_        _ -  | |   -_    " << std::endl;
	file << "         // \\\\                 // \\\\             // \\\\                // \\\\              // \\\\      " << std::endl;
	file.close();
}