#include <iostream>

#include "Base.h"

#include "A.h"
#include "B.h"
#include "C.h"

Base *generate(void) {
	srand(time(NULL));
	int i = rand() % 3;
	if (i == 0) {
		std::cout << "A" << std::endl;
		return new A;
	}
	else if (i == 1) {
		std::cout << "B" << std::endl;
		return new B;
	}
	else {
		std::cout << "C" << std::endl;
		return new C;
	}
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p) != nullptr) {
		std::cout << "A" << std::endl;
		return;
	} else if (dynamic_cast<B*>(p) != nullptr) {
		std::cout << "B" << std::endl;
		return;
	} else if (dynamic_cast<C*>(p) != nullptr) {
		std::cout << "C" << std::endl;
		return;
	}
	std::cout << "Error: Unknown type" << std::endl;
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch (std::exception &e) {
		try {
			B &b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
			(void)b;
		}
		catch (std::exception &e) {
			try {
				C &c = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
				(void)c;
			}
			catch (std::exception &e) {
				std::cout << "Error" << std::endl;
			}
		}
	}
}

int main(void) {

	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;

	return 0;
}