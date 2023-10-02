#ifndef ICE_H
#define ICE_H

#ifndef AMATERIA_H
#include "AMateria.h"
#endif

class Ice: public AMateria {
public:
	Ice();
	Ice(std::string const & type);
	Ice(Ice const &ice);
	Ice & operator=(Ice const &ice);
	virtual ~Ice();
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
