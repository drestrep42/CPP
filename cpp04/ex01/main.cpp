#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

return 0;
}

/* int main()
{
	const Animal animals[10];

	for (int i = 0; i < 5; i++)
		animals[i] = new Dog(); 
} */
