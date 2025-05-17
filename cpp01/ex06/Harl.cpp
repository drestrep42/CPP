#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void	Harl::debug( void ) {
	std::cout << "I love having extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-special "
	<< "ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon "
	<< "costs more money. You didn't put enough bacon in my burger! "
	<< "If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for "
	<< "free. I've been coming for years, whereas you started "
	<< "working here just last month." << std::endl;
}

void	Harl::error( void ) {
	std::cout << "This is unacceptable! I want to "
	<< "speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level ) {

	Harl	harl;

	enum Level {
		DEBUG,
		INFO,
		WARNING,
		ERROR,
	};

	std::map<std::string, int> levelMap;
    levelMap["DEBUG"] = 0;
    levelMap["INFO"] = 1;
    levelMap["WARNING"] = 2;
    levelMap["ERROR"] = 3;

	std::map<std::string, int>::iterator it = levelMap.find(level);
	int lvl = it->second;

	switch (lvl)
	{
		case 0:
			harl.debug();
		case 1:
			harl.info();
		case 2:
			harl.warning();
		case 3:
			harl.error();
			break ;
		default:
			std::cout << "*Mumbling nonsense*" << std::endl;
	}
}
