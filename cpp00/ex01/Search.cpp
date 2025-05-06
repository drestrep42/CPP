/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:06:07 by drestrep          #+#    #+#             */
/*   Updated: 2025/05/06 16:39:34 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	parse_index(std::string str)
{
	int	nbr;
	int	i = -1;

	while (str[++i])
	{
		if (!isdigit(str[i]) && str[i] != ' ')
			return (-1);
	}
	std::istringstream iss(str);
	iss >> nbr;
	return (nbr);
}

void	display_specific_contact(PhoneBook *phonebook)
{
	std::string			str;
	int					index;

	std::cout << "> Select index to display: ";
	std::getline(std::cin, str);
	if (str.empty())
	{
		std::cout << "Empty input" << std::endl;
		return ;
	}
	index = parse_index(str);
	if (index < 0 || index > 7)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	str = phonebook->contact[index].getFirstName();
	if (str.empty())
	{
		std::cout << "Empty contact" << std::endl;
		return ;
	}
	std::cout << "First name: " << phonebook->contact[index].getFirstName() << std::endl;
	std::cout << "Last name: " << phonebook->contact[index].getLastName() << std::endl;
	std::cout << "Nickname: " << phonebook->contact[index].getNickName() << std::endl;
	std::cout << "Phone Number: " << phonebook->contact[index].getPhoneNumber() << std::endl;
}


void	display_info(Contact contact, int *field)
{
	std::string	info;
	std::cout << "|";

	if (contact.getInit() == 0)
		std::cout << std::setw(11);
	else
	{
		if (*field == 0)
			info = contact.getFirstName();
		else if (*field == 1)
			info =  contact.getLastName();
		else if (*field == 2)
			info = contact.getNickName();
		else if (*field == 3)
			info = contact.getPhoneNumber();
		if (info.length() > 10)
		{
			info.resize(10);
			info[9] = '.';
		}
		std::cout << std::right << std::setw(10) << info;
	}
	(*field)++;
}

void	display_contacts(PhoneBook *phonebook)
{
	for (int i = 0; i < 45; i++)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|";
		std::cout << std::right << std::setw(10) << i;
		int	j = 0;
		while (j < 3)
			display_info(phonebook->contact[i], &j);
		std::cout << "|" << std::endl;
		for (int k = 0; k < 45; k++)
			std::cout << "-";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	search(PhoneBook *phonebook)
{
	display_contacts(phonebook);
	display_specific_contact(phonebook);
}
