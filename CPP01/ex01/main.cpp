#include "Zombie.h"

Zombie *zombieHorde(int N, std::string name);

int main() {
	for (int i = 0; i < 5; i++) {
		Zombie *zombies = zombieHorde(i * i, "Zombie");
		for (int j = 0; j < i * i; j++)
			zombies[i].announce();
		delete [] zombies;
	}
	return 0;
}