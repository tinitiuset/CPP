#include "Data.h"

Data::Data() : data(0) {}

Data::Data(int data) : data(data) {}

Data::~Data() {}

Data::Data(const Data &src) {
	*this = src;
}

Data &Data::operator=(const Data &rhs) {
	if (this != &rhs) {
		data = rhs.data;
	}
	return *this;
}

int Data::getData() const {
	return data;
}