#ifndef CLAPTRAP_H
#include "ClapTrap.h"
#endif

#ifndef SCAVTRAP_H
#include "ScavTrap.h"
#endif

#ifndef FRAGTRAP_H
#include "FragTrap.h"
#endif

#ifndef DIAMONDTRAP_H
#include "DiamondTrap.h"
#endif

int main(void) {

	DiamondTrap dt;

	dt.whoAmI();

	dt.highFivesGuys();

	dt.attack("target");

	return 0;
}