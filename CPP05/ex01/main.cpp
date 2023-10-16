#include "Bureaucrat.h"
#include "Form.h"

int main(void) {

	Bureaucrat b1("b1", 1);

	Form f1("f1", 1, 1);

	b1.signForm(f1);

	Bureaucrat b2("b2", 2);

	Form f2("f2", 1, 1);

	b2.signForm(f2);

	try {
		Form f3("f3", 151, 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}