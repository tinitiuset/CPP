#include "Character.h"
#include "MateriaSource.h"
#include "Ice.h"
#include "Cure.h"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	IMateriaSource* src2 = new MateriaSource();
	//src2->learnMateria(new AMateria());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());

	ICharacter* me2 = new Character("me");

	AMateria* tmp2;
	me2->equip(src2->createMateria("yikes"));
	tmp2 = src2->createMateria("ice");
	me2->equip(tmp2);
	me2->equip(tmp2);

	ICharacter* bob2 = new Character("bob");

	me2->use(0, *bob2);
	me2->use(1, *bob2);
	me2->use(2, *bob2);
	me2->use(3, *bob2);
	me2->use(4, *bob2);
	me2->use(5, *bob2);

	me2->unequip(0);
	me2->unequip(0);
	me2->unequip(1);
	me2->unequip(2);

	delete bob2;
	delete me2;
	delete src2;

	return 0;
}