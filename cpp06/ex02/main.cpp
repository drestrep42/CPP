#include "Base.hpp"

int main() {
	srand(static_cast<unsigned int>(time(0)));

	Base* basePtr = generate();
	identify(basePtr);
	identify(*basePtr);

	delete basePtr;
	return 0;
}
