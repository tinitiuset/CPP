#ifndef CPP_DOG_H
#define CPP_DOG_H

#include "iostream"

#ifndef ANIMAL_H
#include "Animal.h"
#endif

#ifndef BRAIN_H
#include "Brain.h"
#endif

class Dog : public Animal {

	private:
		Brain *_brain;

	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();
		void makeSound() const;
		Brain *getBrain() const;
};

#endif
