/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:06:07 by drestrep          #+#    #+#             */
/*   Updated: 2025/05/06 16:39:42 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

void	contactInit(PhoneBook *phonebook)
{
	for (int i = 0; i < 8; i++)
		phonebook->contact[i].setInit(0);
}

int main(int argc, char **argv)
{
	PhoneBook   phonebook;
	std::string input;
	int		    index = 0;

	(void)argv;
	if (argc != 1)
	{
		std::cout << USAGE_ERROR << std::endl;
		return (1);
	}
	contactInit(&phonebook);
	while (true)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl << (char)10;
			exit(0) ;
		}
		if (input == "EXIT")
			exit(0);
		else if (input == "ADD")
			add(&phonebook, &index);
		else if (input == "SEARCH")
			search(&phonebook);
		else if (!input.empty())
			std::cout << INVALID_COMMAND << std::endl;
		std::cout << std::endl;
	}
	return (0);
}
