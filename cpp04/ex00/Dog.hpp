#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog: public Animal
{
	public:
		Dog();
		~Dog();

		Dog(const Dog& copy);
		Dog&	operator=(const Dog& copy);

		std::string	getType();
		void		setType(std::string type);

		void		makeSound() const;
};

#endif