#include "phonebook.h"

phonebook::phonebook() : contacts() {
}

phonebook::phonebook(phonebook &p) : contacts() {
	for (int i = 0; i < 8; i++)
		contacts[i] = p.contacts[i];
}

phonebook::~phonebook() {
}

void phonebook::setContact(int index, const contact &c) {
	contacts[index] = c;
}

contact phonebook::getContact(int index) {
	return (contacts[index]);
}

void phonebook::printHeader() {
	cout << "|";
	cout << setw(10) << "Index" << "|";
	cout << setw(10) << "First Name" << "|";
	cout << setw(10) << "Last Name" << "|";
	cout << setw(10) << "Nickname";
	cout << "|" << endl;
	cout << "|";
	cout << setw(10) << "----------" << "|";
	cout << setw(10) << "----------" << "|";
	cout << setw(10) << "----------" << "|";
	cout << setw(10) << "----------";
	cout << "|" << endl;
}