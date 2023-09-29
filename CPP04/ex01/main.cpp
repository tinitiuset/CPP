#include "Dog.h"
#include "Cat.h"

int main(void) {

	const Animal *j = new Dog();
	const Animal *i = new Cat();

	delete j;
	delete i;

	Animal *animals[8];

	for (int k = 0; k < 8; k+=2)
	{
		animals[k] = new Dog();
		animals[k + 1] = new Cat();
	}

	for (int k = 0; k < 8; k++)
		delete animals[k];

	Cat cat1;
	Cat cat2(cat1);

	std::cout << "Cat Brain 1 is :" << cat1.getBrain() << std::endl;
	std::cout << "Cat Brain 2 is :" << cat2.getBrain() << std::endl;

	Dog dog1;
	Dog dog2;

	dog2 = dog1;

	std::cout << "Cat Brain 1 is :" << dog1.getBrain() << std::endl;
	std::cout << "Cat Brain 2 is :" << dog2.getBrain() << std::endl;

	return 0;
}