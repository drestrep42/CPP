#include "Base.hpp"

Base::~Base() {}

Base* generate(void) {
	int random = rand() % 3;
	switch (random)
	{
		case 0:
			std::cout << "Generated A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generated B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generated C" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Identified A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Identified A" << std::endl;
		return;
	} catch (...) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Identified B" << std::endl;
		return;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Identified C" << std::endl;
		return;
	} catch (...) {}

	std::cout << "Unknown type" << std::endl;
}
