#ifndef CAT_H
#define CAT_H

#include "iostream"

#ifndef ANIMAL_H
#include "Animal.h"
#endif

#ifndef BRAIN_H
#include "Brain.h"
#endif

class Cat : public Animal {

	private:
		Brain *_brain;

	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();
		void makeSound() const;
		Brain *getBrain() const;
};

#endif
