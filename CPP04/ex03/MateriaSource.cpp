#include "MateriaSource.h"

MateriaSource::MateriaSource() : _count(0) {
	for (int i = 0; i < 4; ++i)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &materiaSource) {
	*this = materiaSource;
}

MateriaSource & MateriaSource::operator=(MateriaSource const &materiaSource) {
	if (this != &materiaSource) {
		_count = materiaSource._count;
		for (int i = 0; i < 4; ++i) {
			if (materiaSource._materia[i])
				_materia[i] = materiaSource._materia[i]->clone();
			else
				_materia[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		if (_materia[i])
			delete _materia[i];
	}
}

void MateriaSource::learnMateria(AMateria *materia) {
	if (_count < 4 && materia) {
		_materia[_count] = materia;
		++_count;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; ++i) {
		if (_materia[i] && _materia[i]->getType() == type)
			return _materia[i]->clone();
	}
	return NULL;
}
