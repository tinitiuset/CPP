#ifndef CAT_H
#define CAT_H

#include "iostream"

#ifndef ANIMAL_H
#include "Animal.h"
#endif

class Cat : public Animal {

	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();
		void makeSound() const;
};

#endif
