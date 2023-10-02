#ifndef CURE_H
#define CURE_H

#ifndef AMATERIA_H
#include "AMateria.h"
#endif

class Cure: public AMateria {
public:
	Cure();
	Cure(std::string const & type);
	Cure(Cure const &cure);
	Cure & operator=(Cure const &cure);
	virtual ~Cure();
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
