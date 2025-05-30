#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal();
		virtual ~WrongAnimal();

		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal&	operator=(const WrongAnimal& copy);

		std::string		getType() const;
		void			setType(std::string type);

		virtual void	makeSound() const;
};

#endif