#include "Ice.h"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(std::string const &type) : AMateria(type) {}

Ice::Ice(Ice const &ice) : AMateria(ice) {}

Ice &Ice::operator=(Ice const &ice) {
	if (this != &ice)
		AMateria::operator=(ice);
	return *this;
}

Ice::~Ice() {}

AMateria *Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


