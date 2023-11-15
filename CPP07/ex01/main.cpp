#include <iostream>
#include "iter.h"

void testInt() {
	int arr[] = {1, 2, 3, 4, 5};
	iter(arr, 5, print);
}

void testFloat() {
	float arr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	iter(arr, 5, print);
}

void testString() {
	std::string arr[] = {"Hello", "World", "Test", "Array", "String"};
	iter(arr, 5, print);
}

void testEmpty() {
	int arr[] = {};
	iter(arr, 0, print);
}

int main( void ) {

	std::cout << "Test with int array:" << std::endl;
	testInt();

	std::cout << "Test with float array:" << std::endl;
	testFloat();

	std::cout << "Test with string array:" << std::endl;
	testString();

	std::cout << "Test with empty array:" << std::endl;
	testEmpty();

   return 0;
}