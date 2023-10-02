#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#ifndef IMATERIASOURCE_H
#include "IMateriaSource.h"
#endif

class MateriaSource: public IMateriaSource {

private:
	AMateria* _materia[4];
	int _count;

public:
	MateriaSource();
	MateriaSource(MateriaSource const &materiaSource);
	MateriaSource & operator=(MateriaSource const &materiaSource);
	virtual ~MateriaSource();
	virtual void learnMateria(AMateria* materia);
	virtual AMateria* createMateria(std::string const & type);

};

#endif
