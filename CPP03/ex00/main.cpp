#include "ClapTrap.h"

int main(void) {

	ClapTrap ct1("ct1");
	ClapTrap ct2("ct2");

	ct1.attack("ct2");
	ct2.takeDamage(5);
	ct2.beRepaired(15);

	return 0;
}