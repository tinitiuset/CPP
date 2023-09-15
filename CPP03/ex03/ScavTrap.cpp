#include "ScavTrap.h"

ScavTrap::ScavTrap() : ClapTrap(100, 50, 20, "name") {
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(st) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &st) {
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this != &st) {
		_name = st._name;
		_hitPoints = st._hitPoints;
		_energyPoints = st._energyPoints;
		_attackDamage = st._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(100, 50, 20, name) {
	std::cout << "ScavTrap " << _name << " parameter constructor called" << std::endl;
}

void ScavTrap::attack(std::string const &target) {

	int i;
	for (i = 0; i < _attackDamage; i++) {
		if (_energyPoints)
			_energyPoints--;
		else
			break;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << i << " points of damage!"
			  << std::endl;
	if (!_energyPoints)
		std::cout << "ScavTrap " << _name << " has no energyPoints left!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode" << std::endl;
}