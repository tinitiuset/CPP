#include "Harl.h"

using namespace std;

void Harl::debug(void) {
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger.";
	cout << "I really do!" << endl;
}

void Harl::info(void) {
	cout << "I cannot believe adding extra bacon cost more money.";
	cout << "You don’t put enough! If you did I would not have to ask for it!" << endl;
}

void Harl::warning() {
	cout << "I think I deserve to have some extra bacon for free.";
	cout << "I’ve been coming here for years and you just started working here last month." << endl;
}

void Harl::error(void) {
	cout << "This is unacceptable, I want to speak to the manager now." << endl;
}

void Harl::complain(string level) {
	typedef void (Harl::*function)(void);

	function	functions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	string			levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; i++)
		if (level == levels[i])
			(this->*functions[i])();
}