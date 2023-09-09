#ifndef CLAPTRAP_H
#include "ClapTrap.h"
#endif

#ifndef SCAVTRAP_H
#include "ScavTrap.h"
#endif

#ifndef FRAGTRAP_H
#include "FragTrap.h"
#endif

int main(void) {

	ScavTrap st("1");

	st.attack("target");
	st.attack("target2");

	st.beRepaired(1000);
	st.takeDamage(1000);

	st.guardGate();

	FragTrap ft("2");

	ft.highFivesGuys();

	ft.attack("target");
	ft.attack("target2");

	ft.beRepaired(1000);
	ft.takeDamage(1000);

	return 0;
}