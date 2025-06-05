#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal	*animal[10];
	Dog		dog;

	for (int i = 0; i < 5; i++) {
		animal[i] = new Dog;
	}

	for (int i = 5; i < 10; i++) {
		animal[i] = new Cat;
	}

	std::cout << dog.getIdea(101) << std::endl;
	std::cout << dog.getIdea(-1) << std::endl;
	std::cout << dog.getIdea(1) << std::endl;

	for (int i = 0; i < 101; i++)
		dog.setIdea("This is the idea ", i);

	std::cout << dog.getIdea(1) << std::endl;

	for (int i = 0; i < 10; i++) {
		delete animal[i];
		if (i == 4)
			std::cout << std::endl;
	}
}
