#include "Contact.hpp"

std::string	Contact::getFirstName() {
	return (FirstName);
}

std::string	Contact::getLastName() {
	return (LastName);
}

std::string	Contact::getNickName() {
	return (NickName);
}

std::string	Contact::getPhoneNumber() {
	return (PhoneNumber);
}

std::string	Contact::getDarkestSecret() {
	return (DarkestSecret);
}

int			Contact::getInit() 
{
	return (Init);
}

void	    Contact::setFirstName(std::string s) {
	FirstName = s;
}

void	    Contact::setLastName(std::string s){
	LastName = s;
}

void	    Contact::setNickName(std::string s){
	NickName = s;
}

void	    Contact::setPhoneNumber(std::string s){
	PhoneNumber = s;
}

void	    Contact::setDarkestSecret(std::string s){
	DarkestSecret = s;
}

void	    Contact::setInit(int n){
	Init = n;
}
