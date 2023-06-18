#include "string"
#include "phonebook.h"
#include "iomanip"

using namespace std;

int getContactInfo(contact &c) {
	string t;
	int err = 0;
	cout << "Please enter the contact's first name: ";
	cin >> t;
	t.empty() ? (void) err++ : c.setFirstName(t);
	cout << "Please enter the contact's last name: ";
	cin >> t;
	t.empty() ? (void) err++ : c.setLastName(t);
	cout << "Please enter the contact's nickname: ";
	cin >> t;
	t.empty() ? (void) err++ : c.setNickname(t);
	cout << "Please enter the contact's phone number: ";
	cin >> t;
	t.empty() ? (void) err++ : c.setPhoneNumber(t);
	cout << "Please enter the contact's darkest secret: ";
	cin >> t;
	t.empty() ? (void) err++ : c.setDarkestSecret(t);
	return (err);
}

void addContact(phonebook &book) {
	static int times;
	contact c;
	if (!getContactInfo(c)) {
		book.setContact(times % 8, c);
		times++;
	} else
		cout << "Invalid input" << endl;
}

void searchContact(phonebook &book) {
	int index = 0;

	phonebook::printHeader();
	while (book.getContact(index).getFirstName().length() > 0 && index < 8) {
		book.getContact(index).printTable(index);
		index++;
	}
	index = 0;
	cout << "Please enter the index of the contact you wish to view: ";
	cin >> index;
	if (index >= 0 && index < 8 && book.getContact(index).getFirstName().length() > 0)
		book.getContact(index).printFull();
	else
		cout << "Invalid index" << endl;
}

int main() {

	string option;
	phonebook book;

	cout << "Welcome to the Phonebook" << endl;
	while (option != "EXIT") {
		cout << "Please enter an option: ADD, SEARCH or EXIT" << endl;
		cin >> option;
		if (option == "ADD") {
			addContact(book);
		} else if (option == "SEARCH") {
			searchContact(book);
		} else if (option == "EXIT")
			break;
		else
			cout << "Invalid option" << endl;
	}
	return (0);
}