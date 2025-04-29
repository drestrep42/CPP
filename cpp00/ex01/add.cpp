/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:06:07 by drestrep          #+#    #+#             */
/*   Updated: 2025/04/24 18:23:30 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassContact.hpp"
#include "ClassPhoneBook.hpp"

void	set_info(std::string info, std::string *input)
{
	std::cout << info;
	while (std::getline(std::cin, *input))
	{
		while (input->empty())
		{
			std::cout << "There cannot be an empty input" << std::endl;
			std::cout << info;
			std::getline(std::cin, *input);
		}
		return ;
	}
	std::cout << std::endl;
	exit(0);
}

void	add(PhoneBook *phonebook, int *index)
{
	std::string input;

	phonebook->contact[*index].setInit(1);
	set_info("First Name: ", &input);
	phonebook->contact[*index].setFirstName(input);
	set_info("Last Name: ", &input);
	phonebook->contact[*index].setLastName(input);
	set_info("Nickname: ", &input);
	phonebook->contact[*index].setNickName(input);
	set_info("Phone Number: ", &input);
	phonebook->contact[*index].setPhoneNumber(input);
	set_info("Darkest Secret: ", &input);
	phonebook->contact[*index].setDarkestSecret(input);
	*index = ((*index) + 1) % 8;
}
