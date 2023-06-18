#include "contact.h"

contact::contact() : firstName(), lastName(), nickname(), phoneNumber(), darkestSecret() {
}

contact::contact(contact &c) : firstName(c.firstName), lastName(c.lastName), nickname(c.nickname),
							   phoneNumber(c.phoneNumber), darkestSecret(c.darkestSecret) {
}

contact::~contact() {
}

void contact::setFirstName(std::string f) {
	firstName = f;
}

void contact::setLastName(std::string l) {
	lastName = l;
}

void contact::setNickname(std::string n) {
	nickname = n;
}

void contact::setPhoneNumber(std::string p) {
	phoneNumber = p;
}

void contact::setDarkestSecret(std::string d) {
	darkestSecret = d;
}

std::string contact::getFirstName() {
	return (firstName);
}

std::string contact::getLastName() {
	return (lastName);
}

std::string contact::getNickname() {
	return (nickname);
}

std::string contact::getPhoneNumber() {
	return (phoneNumber);
}

std::string contact::getDarkestSecret() {
	return (darkestSecret);
}

void contact::printFull() {
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Nickname: " << nickname << endl;
	cout << "Phone Number: " << phoneNumber << endl;
	cout << "Darkest Secret: " << darkestSecret << endl;
}

void contact::printTable(int index) {
	cout << "|";
	cout << setw(10) << index << "|";
	cout << setw(10) << trim(firstName) << "|";
	cout << setw(10) << trim(lastName) << "|";
	cout << setw(10) << trim(nickname);
	cout << "|" << endl;
}

string contact::trim(const string &s) {
	if (s.length() > 10)
		return (s.substr(0, 9) + ".");
	return (s);
}