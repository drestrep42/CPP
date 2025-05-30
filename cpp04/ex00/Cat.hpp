#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat: public Animal
{
	public:
		Cat();
		~Cat();

		Cat(const Cat& copy);
		Cat&	operator=(const Cat& copy);

		std::string	getType();
		void		setType(std::string type);

		void		makeSound() const;
};

#endif