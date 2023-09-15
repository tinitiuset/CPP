#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>

#ifndef CLAPTRAP_H

#include "ClapTrap.h"

#endif

class FragTrap : virtual public ClapTrap {

	// In order to access the attributes of superClass
	// Declare them as protected

public:
	FragTrap();

	FragTrap(std::string name);

	FragTrap(const FragTrap &other);

	FragTrap &operator=(const FragTrap &other);

	~FragTrap();

	void attack(std::string const &target);

	void highFivesGuys();
};

#endif
