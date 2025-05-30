#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: virtual public Animal
{
	private:
		Brain*	_brain;

	public:
		Dog();
		~Dog();

		Dog(const Dog& copy);
		Dog&	operator=(const Dog& copy);

		std::string	getType();
		void		setType(std::string type);

		std::string	getIdea(int nbr) const;
		void		setIdea(std::string idea, int nbr);

		void		makeSound() const;

};

#endif