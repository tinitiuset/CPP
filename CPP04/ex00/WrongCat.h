#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "iostream"

#ifndef WRONGANIMAL_H
#include "WrongAnimal.h"
#endif

class WrongCat : public WrongAnimal {

	public:
		WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &other);
		~WrongCat();
		void makeSound() const;
};

#endif
