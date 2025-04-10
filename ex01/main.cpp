/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:06:07 by drestrep          #+#    #+#             */
/*   Updated: 2025/04/10 18:37:14 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassContact.hpp"
#include "ClassPhoneBook.hpp"

void    add(PhoneBook *phonebook, int i)
{
    std::string input;
    std::cout << "First Name: ";
    std::cin >> input;
    phonebook->contact[0].setFirstName(input);
    std::cout << "Last Name: ";
    std::cin >> input;
    phonebook->contact[0].setLastName(input);
    std::cout << "Nick Name: ";
    std::cin >> input;
    phonebook->contact[0].setNickName(input);
    std::cout << "Phone Number: ";
    std::cin >> input;
    phonebook->contact[0].setPhoneNumber(input);
    std::cout << "Darkest Secret: ";
    std::cin >> input;
    phonebook->contact[0].setDarkestSecret(input);
}

int main(int argc, char **argv)
{
    PhoneBook   phonebook;
    std::string input;
    int         index;

    if (argc != 1)
    {
        std::cout << USAGE_ERROR << std::endl;
        exit(1);
    }
    while (true)
    {
        std::cout << ">";
        std::cin >> input;
        std::cout << input << std::endl;
        if (input.compare("EXIT") == 0)
            exit(0);
        else if (input.compare("ADD") == 0)
            add(&phonebook, index);
    }
}
