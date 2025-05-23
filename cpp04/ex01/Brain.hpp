#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		~Brain();

		Brain(const Brain& copy);
		Brain&	operator=(const Brain& copy);

		std::string	getIdeas(int nbr) const;
		void		setIdeas(std::string idea, int nbr);
};

#endif