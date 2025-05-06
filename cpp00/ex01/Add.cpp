#include "Contact.hpp"
#include "PhoneBook.hpp"

bool	check_alpha(std::string	*s)
{
	for (std::string::iterator it = s->begin(); it != s->end(); ++it)
	{
    	if (!isalnum(static_cast<unsigned char>(*it)))
        	return false;
	}
	return (true);
}

void	set_info(std::string info, std::string *input, int recur)
{
	if (recur == 0)
		std::cout << info;
	while (std::getline(std::cin, *input))
	{
		while (check_alpha(input) == false)
		{
			std::cout << "Only letters and numbers allowed" << std::endl;
			std::cout << info;
			set_info(info, input, 1);
		}
		while (input->empty())
		{
			std::cout << "There cannot be an empty input" << std::endl;
			std::cout << info;
			set_info(info, input, 1);
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
	set_info("First Name: ", &input, 0);
	phonebook->contact[*index].setFirstName(input);
	set_info("Last Name: ", &input, 0);
	phonebook->contact[*index].setLastName(input);
	set_info("Nickname: ", &input, 0);
	phonebook->contact[*index].setNickName(input);
	set_info("Phone Number: ", &input, 0);
	phonebook->contact[*index].setPhoneNumber(input);
	set_info("Darkest Secret: ", &input, 0);
	phonebook->contact[*index].setDarkestSecret(input);
	*index = ((*index) + 1) % 8;
}
