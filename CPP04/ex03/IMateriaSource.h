#ifndef IMATERIASOURCE_H
#define IMATERIASOURCE_H

#ifndef AMATERIA_H
#include "AMateria.h"
#endif

class IMateriaSource {
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif