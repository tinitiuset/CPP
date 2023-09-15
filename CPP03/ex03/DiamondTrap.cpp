#include "DiamondTrap.h"

DiamondTrap::DiamondTrap() : ClapTrap(100, 50, 30, "Default Name_clap_name"), ScavTrap(), FragTrap(), _name("Default Name") {
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &a) : ClapTrap(a), ScavTrap(a) , FragTrap(a), _name(a._name) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &a) {
	std::cout << "DiamondTrap assignation operator called" << std::endl;
	if (this != &a) {
		_name = a._name;
		_hitPoints = a._hitPoints;
		_energyPoints = a._energyPoints;
		_attackDamage = a._attackDamage;
	}
	return *this;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(100, 50, 30, name + "_clap_name"), ScavTrap(), FragTrap(), _name(name) {
	std::cout << "DiamondTrap " << _name << " parameter constructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name is " << _name << std::endl;
	std::cout << "ClapTrap name is " << ClapTrap::_name << std::endl;
}

