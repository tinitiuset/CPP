#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iostream>
#include "Data.h"

class Serializer {
private:
	Serializer(const Serializer &src);
	Serializer &operator=(const Serializer &rhs);

public:
	Serializer();
	~Serializer();
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

};


#endif
