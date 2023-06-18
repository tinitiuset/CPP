#ifndef CPP_CONTACT_H
#define CPP_CONTACT_H

#include "iostream"
#include "iomanip"

using namespace std;

class contact {

private:
	string firstName;
	string lastName;
	string nickname;
	string phoneNumber;
	string darkestSecret;

public:
	contact();

	contact(contact &c);

	~contact();

	void setFirstName(string f);

	void setLastName(string l);

	void setNickname(string n);

	void setPhoneNumber(string p);

	void setDarkestSecret(string d);

	string getFirstName();

	string getLastName();

	string getNickname();

	string getPhoneNumber();

	string getDarkestSecret();

	void printFull();

	void printTable(int index);

	static string trim(const string &s);
};

#endif
