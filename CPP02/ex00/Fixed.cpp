#include "Fixed.h"

using namespace std;

Fixed::Fixed() {
	cout << "Default constructor called" << endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &fixed) {
	cout << "Copy constructor called" << endl;
	*this = fixed;
}

Fixed::~Fixed() {
	cout << "Destructor called" << endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	cout << "Copy assignment operator called" << endl;
	this->value = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	cout << "getRawBits member function called" << endl;
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	cout << "setRawBits member function called" << endl;
	this->value = raw;
}