#ifndef CLAPTRAP_H
#include "ClapTrap.h"
#endif

#ifndef SCAVTRAP_H
#include "ScavTrap.h"
#endif

int main(void) {

	ScavTrap st("1");

	st.attack("target");
	st.attack("target2");

	st.beRepaired(1000);
	st.takeDamage(1000);

	st.guardGate();

	return 0;
}