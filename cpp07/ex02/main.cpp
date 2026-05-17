#include "Array.hpp"
#include "Array.tpp"
#include <iostream>

int main (void) {

	int* a = new int(42);
	std::cout << "Value of a: " << *a << std::endl;
	delete a;

	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i + 1;

	std::cout << "Original array: ";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	Array<int> copy(arr);
	std::cout << "Copy of original array: ";
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
	std::cout << std::endl;

	copy[0] = 42;
	std::cout << "Modified copy: ";
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
	std::cout << std::endl;

	std::cout << "Original array after modifying copy: ";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	try {
		std::cout << "Accessing out of range index: " << arr[10] << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	return 0;
}
