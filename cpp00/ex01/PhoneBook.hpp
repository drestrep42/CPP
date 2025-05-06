#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class   PhoneBook  {
    public:
        Contact contact[8];
};

void	add(PhoneBook *phonebook, int *index);
void	search(PhoneBook *phonebook);

#endif