#ifndef CPP_PHONEBOOK_H
#define CPP_PHONEBOOK_H

#include "iostream"
#include "contact.h"
#include "iomanip"

class phonebook {

private:
	contact contacts[8];

public:
	phonebook();

	phonebook(phonebook &p);

	~phonebook();

	void setContact(int index, const contact &c);

	contact getContact(int index);

	static void printHeader();
};


#endif