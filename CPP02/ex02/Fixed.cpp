#include "Fixed.h"

Fixed::Fixed() {
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int value) {
	if (DEBUG)
		std::cout << "Int constructor called" << std::endl;
	this->value = value << this->bits;
}

Fixed::Fixed(const float value) {
	if (DEBUG)
		std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << this->bits));
}

Fixed::Fixed(const Fixed &fixed) {
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed() {
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	if (DEBUG)
		std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	if (DEBUG)
		std::cout << "setRawBits member function called" << std::endl;
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
		std::cout << "Copy assignment operator called" << std::endl;
	this->value = fixed.value;
	return *this;
}

bool Fixed::operator>(const Fixed &fixed) const {
	if (DEBUG)
		std::cout << "Greater than operator called" << std::endl;
	return this->getRawBits() > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const {
	if (DEBUG)
		std::cout << "Less than operator called" << std::endl;
	return this->getRawBits() < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const {
	if (DEBUG)
		std::cout << "Greater than or equal operator called" << std::endl;
	return this->getRawBits() >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const {
	if (DEBUG)
		std::cout << "Less than or equal operator called" << std::endl;
	return this->getRawBits() <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const {
	if (DEBUG)
		std::cout << "Equal operator called" << std::endl;
	return this->getRawBits() == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const {
	if (DEBUG)
		std::cout << "Not equal operator called" << std::endl;
	return this->getRawBits() != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const {
	if (DEBUG)
		std::cout << "Addition operator called" << std::endl;
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	if (DEBUG)
		std::cout << "Subtraction operator called" << std::endl;
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
	if (DEBUG)
		std::cout << "Multiplication operator called" << std::endl;
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
	if (DEBUG)
		std::cout << "Division operator called" << std::endl;
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed Fixed::operator++(void) {
	if (DEBUG)
		std::cout << "Pre-increment operator called" << std::endl;
	this->value++;
	return *this;
}

Fixed Fixed::operator--(void) {
	if (DEBUG)
		std::cout << "Pre-decrement operator called" << std::endl;
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	if (DEBUG)
		std::cout << "Post-increment operator called" << std::endl;
	Fixed fixed = Fixed(*this);
	this->value = this->value + 1;
	return fixed;
}

Fixed Fixed::operator--(int) {
	if (DEBUG)
		std::cout << "Post-decrement operator called" << std::endl;
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

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
	o << i.toFloat();
	return o;
}