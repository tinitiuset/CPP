#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>

#ifndef CLAPTRAP_H

#include "ClapTrap.h"

#endif

class ScavTrap : virtual public ClapTrap {

	// In order to access the attributes of superClass
	// Declare them as protected

public:
	ScavTrap();

	ScavTrap(std::string name);

	ScavTrap(const ScavTrap &other);

	ScavTrap &operator=(const ScavTrap &other);

	~ScavTrap();

	void attack(std::string const &target);

	void guardGate();
};

#endif
