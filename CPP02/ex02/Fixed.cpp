#include "Fixed.h"

using namespace std;

Fixed::Fixed() {
	if (DEBUG)
		cout << "Default constructor called" << endl;
	this->value = 0;
}

Fixed::Fixed(const int value) {
	if (DEBUG)
		cout << "Int constructor called" << endl;
	this->value = value << this->bits;
}

Fixed::Fixed(const float value) {
	if (DEBUG)
		cout << "Float constructor called" << endl;
	this->value = roundf(value * (1 << this->bits));
}

Fixed::Fixed(const Fixed &fixed) {
	if (DEBUG)
		cout << "Copy constructor called" << endl;
	*this = fixed;
}

Fixed::~Fixed() {
	if (DEBUG)
		cout << "Destructor called" << endl;
}

int Fixed::getRawBits(void) const {
	if (DEBUG)
		cout << "getRawBits member function called" << endl;
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	if (DEBUG)
		cout << "setRawBits member function called" << endl;
	this->value = raw;
}

float Fixed::toFloat(void) const {
	return (float) this->value / (1 << this->bits);
}

int Fixed::toInt(void) const {
	return this->value >> this->bits;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	if (DEBUG)
		cout << "Copy assignment operator called" << endl;
	this->value = fixed.value;
	return *this;
}

bool Fixed::operator>(const Fixed &fixed) {
	if (DEBUG)
		cout << "Greater than operator called" << endl;
	return this->getRawBits() > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) {
	if (DEBUG)
		cout << "Less than operator called" << endl;
	return this->getRawBits() < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) {
	if (DEBUG)
		cout << "Greater than or equal operator called" << endl;
	return this->getRawBits() >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) {
	if (DEBUG)
		cout << "Less than or equal operator called" << endl;
	return this->getRawBits() <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) {
	if (DEBUG)
		cout << "Equal operator called" << endl;
	return this->getRawBits() == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) {
	if (DEBUG)
		cout << "Not equal operator called" << endl;
	return this->getRawBits() != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) {
	if (DEBUG)
		cout << "Addition operator called" << endl;
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) {
	if (DEBUG)
		cout << "Subtraction operator called" << endl;
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) {
	if (DEBUG)
		cout << "Multiplication operator called" << endl;
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) {
	if (DEBUG)
		cout << "Division operator called" << endl;
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed Fixed::operator++(void) {
	if (DEBUG)
		cout << "Pre-increment operator called" << endl;
	this->value++;
	return *this;
}

Fixed Fixed::operator--(void) {
	if (DEBUG)
		cout << "Pre-decrement operator called" << endl;
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	if (DEBUG)
		cout << "Post-increment operator called" << endl;
	Fixed fixed = Fixed(*this);
	this->value = this->value + 1;
	return fixed;
}

Fixed Fixed::operator--(int) {
	if (DEBUG)
		cout << "Post-decrement operator called" << endl;
	Fixed fixed = Fixed(*this);
	this->value = this->value - 1;
	return fixed;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return a.getRawBits() < b.getRawBits() ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return a.getRawBits() < b.getRawBits() ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return a.getRawBits() > b.getRawBits() ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return a.getRawBits() > b.getRawBits() ? a : b;
}

ostream &operator<<(ostream &o, Fixed const &i) {
	o << i.toFloat();
	return o;
}