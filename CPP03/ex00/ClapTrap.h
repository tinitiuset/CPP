#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap {

private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;

public:
	ClapTrap();

	ClapTrap(std::string name);

	ClapTrap(const ClapTrap &other);

	ClapTrap &operator=(const ClapTrap &other);

	~ClapTrap();

	void attack(std::string const &target);

	void takeDamage(unsigned int amount);

	void beRepaired(unsigned int amount);

};

#endif
