#include "HumanA.hpp"

HumanA::HumanA(std::string s, Weapon &w) : name(s), weapon (w) {}
HumanA::~HumanA() {}

void	HumanA::attack(void) {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
