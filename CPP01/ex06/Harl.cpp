#include "Harl.h"

using namespace std;

Harl::Harl(const string& level) {
	string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	this->minLevel = DEFAULT;
	for (int i = 0; i < 4; i++)
		if (level == levels[i])
			this->minLevel = static_cast<Level>(i + 1);
}

void Harl::debug(void) {
	cout << "[ DEBUG ]" << endl;
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger.";
	cout << "I really do!" << endl;
}

void Harl::info(void) {
	cout << "[ INFO ]" << endl;
	cout << "I cannot believe adding extra bacon cost more money.";
	cout << "You don’t put enough! If you did I would not have to ask for it!" << endl;
}

void Harl::warning() {
	cout << "[ WARNING ]" << endl;
	cout << "I think I deserve to have some extra bacon for free.";
	cout << "I’ve been coming here for years and you just started working here last month." << endl;
}

void Harl::error(void) {
	cout << "[ ERROR ]" << endl;
	cout << "This is unacceptable, I want to speak to the manager now." << endl;
}

void Harl::complain(string level) {

	string levels[] = {"DEFAULT", "DEBUG", "INFO", "WARNING", "ERROR" };

	int j = 0;

	for (int i = 0; i <= 4; i++)
		if (level == levels[i])
			if (i + 1 > this->minLevel)
				j = i;

	switch (j) {
		case DEBUG:
			this->debug();
			break;
		case INFO:
			this->info();
			break;
		case WARNING:
			this->warning();
			break;
		case ERROR:
			this->error();
			break;
		default:
			cout << "[ Probably complaining about insignificant problems ]" << endl;
			break;
	}
}
