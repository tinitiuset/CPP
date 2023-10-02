#include "AMateria.h"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(AMateria const &aMateria) {
	*this = aMateria;
}

AMateria &AMateria::operator=(AMateria const &aMateria) {
	if (this != &aMateria)
		_type = aMateria._type;
	return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter &target) {
	(void)target;
}