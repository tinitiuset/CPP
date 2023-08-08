#include "Fixed.h"

using namespace std;

Fixed::Fixed() {
	cout << "Default constructor called" << endl;
	this->value = 0;
}

Fixed::Fixed(const int value) {
	cout << "Int constructor called" << endl;
	this->value = value << this->bits;
}

Fixed::Fixed(const float value) {
	cout << "Float constructor called" << endl;
	this->value = roundf(value * (1 << this->bits));
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
	this->value = fixed.value;
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

float Fixed::toFloat(void) const {
	return (float) this->value / (1 << this->bits);
}

int Fixed::toInt(void) const {
	return this->value >> this->bits;
}

ostream &operator<<(ostream &o, Fixed const &i) {
	o << i.toFloat();
	return o;
}