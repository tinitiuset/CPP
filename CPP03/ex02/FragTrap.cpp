#include "FragTrap.h"

FragTrap::FragTrap() : ClapTrap(100, 100, 30, "name") {
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &st) : ClapTrap(st) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &st) {
	std::cout << "FragTrap assignation operator called" << std::endl;
	if (this != &st) {
		_name = st._name;
		_hitPoints = st._hitPoints;
		_energyPoints = st._energyPoints;
		_attackDamage = st._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(100, 100, 30, name) {
	std::cout << "FragTrap " << _name << " parameter constructor called" << std::endl;
}

void FragTrap::attack(std::string const &target) {

	int i;
	for (i = 0; i < _attackDamage; i++) {
		if (_energyPoints)
			_energyPoints--;
		else
			break;
	}
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << i << " points of damage!"
			  << std::endl;
	if (!_energyPoints)
		std::cout << "FragTrap " << _name << " has no energyPoints left!" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << " requests positive High Fives!" << std::endl;
}