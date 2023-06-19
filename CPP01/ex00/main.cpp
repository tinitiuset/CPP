#include "Zombie.h"

Zombie *newZombie(std::string name);

void randomChump(std::string name);

int main() {
	Zombie *zombie = newZombie("Zombie");
	zombie->announce();
	delete zombie;
	randomChump("Zombie");
	return (0);
}