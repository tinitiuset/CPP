#include "Fixed.h"

using namespace std;

Fixed::Fixed() {
	this->value = 0;
}

Fixed::Fixed(const int value) {
	this->value = value << this->bits;
}

Fixed::Fixed(const float value) {
	this->value = roundf(value * (1 << this->bits));
}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits(void) const {
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float Fixed::toFloat(void) const {
	return (float) this->value / (1 << this->bits);
}

int Fixed::toInt(void) const {
	return this->value >> this->bits;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	this->value = fixed.value;
	return *this;
}

bool Fixed::operator>(const Fixed &fixed) const {
	return this->getRawBits() > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const {
	return this->getRawBits() < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const {
	return this->getRawBits() >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const {
	return this->getRawBits() <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const {
	return this->getRawBits() == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const {
	return this->getRawBits() != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const {
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed Fixed::operator++(void) {
	this->value++;
	return *this;
}

Fixed Fixed::operator--(void) {
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed fixed = Fixed(*this);
	this->value = this->value + 1;
	return fixed;
}

Fixed Fixed::operator--(int) {
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