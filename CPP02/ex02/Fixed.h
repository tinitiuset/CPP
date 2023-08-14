#ifndef FIXED_H
#define FIXED_H

#include <iostream>

#define DEBUG 0

class Fixed {

private:
	int value;
	static const int bits = 8;

public:
	Fixed();

	Fixed(const int value);

	Fixed(const float value);

	Fixed(const Fixed &fixed);

	~Fixed();

	int getRawBits(void) const;

	void setRawBits(int const raw);

	float toFloat(void) const;

	int toInt(void) const;

	Fixed &operator=(const Fixed &fixed);

	bool operator>(const Fixed &fixed);

	bool operator<(const Fixed &fixed);

	bool operator>=(const Fixed &fixed);

	bool operator<=(const Fixed &fixed);

	bool operator==(const Fixed &fixed);

	bool operator!=(const Fixed &fixed);

	Fixed operator+(const Fixed &fixed);

	Fixed operator-(const Fixed &fixed);

	Fixed operator*(const Fixed &fixed);

	Fixed operator/(const Fixed &fixed);

	// https://www.ibm.com/docs/en/xl-c-and-cpp-aix/16.1?topic=only-overloading-increment-decrement-operators-c
	// The compiler uses the int argument to distinguish between the prefix and postfix increment operators.

	Fixed operator++(void); // prefix

	Fixed operator--(void);

	Fixed operator++(int); // postfix

	Fixed operator--(int);

	static Fixed &min(Fixed &a, Fixed &b);

	static Fixed &max(Fixed &a, Fixed &b);

	static const Fixed &min(const Fixed &a, const Fixed &b);

	static const Fixed &max(const Fixed &a, const Fixed &b);

};

std::ostream &operator<<(std::ostream &o, Fixed const &i);


#endif
