#include "AForm.h"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false),
																			 _gradeToSign(gradeToSign),
																			 _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign),
								 _gradeToExecute(src._gradeToExecute) {
	*this = src;
}

AForm::~AForm() {}

AForm &AForm::operator=(AForm const &src) {
	if (this != &src)
		_signed = src._signed;
	return *this;
}

std::string const &AForm::getName() const { return _name; }

bool AForm::getSigned() const { return _signed; }

int AForm::getGradeToSign() const { return _gradeToSign; }

int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	else
		_signed = true;
}

void AForm::execute(const Bureaucrat &executor) const {
	if (!_signed)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form not signed";
}

std::ostream &operator<<(std::ostream &out, AForm const &src) {
	out << src.getName() << ", form grade to sign " << src.getGradeToSign() << ", form grade to execute "
		<< src.getGradeToExecute() << ", form signed " << src.getSigned() << std::endl;
	return out;
}