#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	//Animal	test;
	Animal	*animal[10];

	for (int i = 0; i < 5; i++) {
		animal[i] = new Dog;
	}

	for (int i = 5; i < 10; i++) {
		animal[i] = new Cat;
	}

	for (int i = 0; i < 10; i++) {
		delete animal[i];
		if (i == 4)
			std::cout << std::endl;
	}
}
