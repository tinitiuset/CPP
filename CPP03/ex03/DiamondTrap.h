#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include <iostream>

#ifndef FRAGTRAP_H

#include "FragTrap.h"

#endif

#ifndef SCAVTRAP_H

#include "ScavTrap.h"

#endif

class DiamondTrap : public ScavTrap, public FragTrap {

private:
	std::string _name;

public:
	DiamondTrap();

	DiamondTrap(const DiamondTrap &a);

	~DiamondTrap();

	DiamondTrap & operator = (const DiamondTrap &a);

	DiamondTrap(std::string name);

	void attack(std::string const &target);

	void whoAmI();

};


#endif
