#include "Zombie.h"

Zombie::Zombie() {
	std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << name << " destroyed" << std::endl;
}

void Zombie::announce() {
	std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string n) {
	name = n;
}

std::string Zombie::get_name() {
	return name;
}

