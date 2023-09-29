#include "Dog.h"

Dog::Dog() : Animal("Dog") {
	_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) {
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &other) {
		_type = other._type;
		*_brain = *other._brain;
	}
	return *this;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof" << std::endl;
}

Brain *Dog::getBrain() const {
	return _brain;
}
