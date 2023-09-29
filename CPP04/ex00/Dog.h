#ifndef CPP_DOG_H
#define CPP_DOG_H

#include "iostream"

#ifndef ANIMAL_H
#include "Animal.h"
#endif

class Dog : public Animal {

	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();
		void makeSound() const;
};

#endif
