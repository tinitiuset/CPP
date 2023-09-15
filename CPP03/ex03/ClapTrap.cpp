#include "ClapTrap.h"

ClapTrap::ClapTrap() : _name("name"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct) : _name(ct._name), _hitPoints(ct._hitPoints), _energyPoints(ct._energyPoints),
										 _attackDamage(ct._attackDamage) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ct) {
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &ct) {
		_name = ct._name;
		_hitPoints = ct._hitPoints;
		_energyPoints = ct._energyPoints;
		_attackDamage = ct._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap(unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage, std::string name) {
	std::cout << "ClapTrap " << _name << " full parameter constructor called" << std::endl;
	_name = name;
	_hitPoints = hitPoints;
	_energyPoints = energyPoints;
	_attackDamage = attackDamage;
}

void ClapTrap::attack(std::string const &target) {

	int i;
	for (i = 0; i < _attackDamage; i++) {
		if (_energyPoints)
			_energyPoints--;
		else
			break;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << i << " points of damage!"
			  << std::endl;
	if (!_energyPoints)
		std::cout << "ClapTrap " << _name << " has no energyPoints left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

	unsigned int i;
	for (i = 0; i < amount; i++) {
		if (_hitPoints)
			_hitPoints--;
		else
			break;
	}
	std::cout << "ClapTrap " << _name << " takes " << i << " points of damage!" << std::endl;
	if (!_hitPoints)
		std::cout << "ClapTrap " << _name << " has no hitPoints left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {

	unsigned int i;
	for (i = 0; i < amount; i++) {
		if (_energyPoints) {
			_hitPoints++;
			_energyPoints--;
		} else
			break;
	}
	std::cout << "ClapTrap " << _name << " is repaired by " << i << " points!" << std::endl;
	if (!_energyPoints)
		std::cout << "ClapTrap " << _name << " has no energyPoints left!" << std::endl;
}