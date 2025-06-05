#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	const WrongAnimal *falseAnimal = new WrongAnimal();
	const WrongAnimal *falseCat = new WrongCat();

	std::cout << falseCat->getType() << std::endl;
	falseCat->makeSound();
	falseAnimal->makeSound();

	delete(meta);
	delete(j);
	delete(i);
	delete(falseAnimal);
	delete(falseCat);

	return (0);
}
