#include <iostream>

#include "Data.h"
#include "Serializer.h"

int main(void) {

	Data *data = new Data(2);

	std::cout << "Data: " << data->getData() << std::endl;

	uintptr_t raw = Serializer::serialize(data);

	std::cout << "Data serialized: " << raw << std::endl;

	Data *data2 = Serializer::deserialize(raw);

	std::cout << "Data deserialized: " << data2->getData() << std::endl;

	delete data2;

	return 0;
}