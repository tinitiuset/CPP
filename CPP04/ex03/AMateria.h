#ifndef AMATERIA_H
#define AMATERIA_H

#include "iostream"

#ifndef ICHARACTER_H
#include "ICharacter.h"
#endif

class ICharacter;

class AMateria {

protected:
	std::string _type;

public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(AMateria const &materia);
	AMateria & operator=(AMateria const &materia);
	virtual ~AMateria();
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

};

#endif
