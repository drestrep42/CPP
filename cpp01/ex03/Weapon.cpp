#include "Weapon.hpp"

Weapon::Weapon() {}
Weapon::Weapon(std::string param) : type(param) {}
Weapon::~Weapon() {}

const	std::string	&Weapon::getType( void ) const {
	return (type);
}

void	Weapon::setType(std::string value) {
	type = value;
}
