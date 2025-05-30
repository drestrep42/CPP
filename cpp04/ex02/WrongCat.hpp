#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();

		WrongCat(const WrongCat& copy);
		WrongCat&	operator=(const WrongCat& copy);

		std::string	getType();
		void		setType(std::string type);

		void		makeSound() const;
};

#endif