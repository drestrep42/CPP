#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <sstream>

class Brain
{
	private:
		std::string _idea[100];

	public:
		Brain();
		~Brain();

		Brain(const Brain& copy);
		Brain&	operator=(const Brain& copy);

		std::string	getIdea(int nbr) const;
		void		setIdea(std::string idea, int nbr);
};

#endif
