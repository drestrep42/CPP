#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain*	_brain;

	public:
		Cat();
		~Cat();

		Cat(const Cat& copy);
		Cat&	operator=(const Cat& copy);

		std::string	getType();
		void		setType(std::string type);

		std::string	getIdea(int nbr) const;
		void		setIdea(std::string idea, int nbr);

		void		makeSound() const;

};

#endif