#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <stdlib.h>
#include <signal.h>
#include <limits.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#define	USAGE_ERROR "Correct use: ./phonebook"
#define INVALID_COMMAND "Invalid command"

class Contact
{
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string	NickName;
		std::string	PhoneNumber;
		std::string	DarkestSecret;
		int	Init;

	public:
        std::string	getFirstName();
        std::string	getLastName();
        std::string	getNickName();
        std::string	getPhoneNumber();
        std::string	getDarkestSecret();
		int			getInit();
		void	    setFirstName(std::string s);
		void	    setLastName(std::string s);
		void	    setNickName(std::string s);
		void	    setPhoneNumber(std::string s);
		void	    setDarkestSecret(std::string s);
		void		setInit(int n);
};

#endif