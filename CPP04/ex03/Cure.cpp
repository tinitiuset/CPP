#include "Cure.h"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(std::string const &type) : AMateria(type) {}

Cure::Cure(Cure const &cure) : AMateria(cure) {}

Cure &Cure::operator=(Cure const &cure) {
	if (this != &cure)
		AMateria::operator=(cure);
	return *this;
}

Cure::~Cure() {}

AMateria *Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
