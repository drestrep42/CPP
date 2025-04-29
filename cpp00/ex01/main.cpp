/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:06:07 by drestrep          #+#    #+#             */
/*   Updated: 2025/04/24 18:23:03 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassContact.hpp"
#include "ClassPhoneBook.hpp"

int main(int argc, char **argv)
{
	PhoneBook   phonebook;
	std::string input;
	int		    index = 0;

	if (argc != 1)
	{
		std::cout << USAGE_ERROR << std::endl;
		return (1);
	}
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
			search(&phonebook, index);
		else if (!input.empty())
			std::cout << INVALID_COMMAND << std::endl;
		std::cout << std::endl;
	}
	return (0);
}
