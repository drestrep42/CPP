#include "easyfind.hpp"

int main ()
{
    std::vector<int> vecInt;
	vecInt.push_back(1);
    vecInt.push_back(3);
    vecInt.push_back(5);

    std::vector<int>::iterator it;
	{
    	try {
    	    it = easyfind(vecInt, 3);
    	    std::cout << "Found: " << *it << std::endl;
    	} catch (const std::runtime_error& e) {
    	    std::cout << e.what() << std::endl;
    	}
	}

	{
    	try {
    	    it = easyfind(vecInt, 6);
    	    std::cout << "Found: " << *it << std::endl;
    	} catch (const std::runtime_error& e) {
    	    std::cout << e.what() << std::endl;
    	}
	}

	std::cout << std::endl << std::endl;

	std::vector<char> vecChar;
	vecChar.push_back('a');
	vecChar.push_back('b');
	vecChar.push_back('c');

	std::vector<char>::iterator itChar;

	{
    	try {
    	    itChar = easyfind(vecChar, 'b');
    	    std::cout << "Found: " << *itChar << std::endl;
    	} catch (const std::runtime_error& e) {
    	    std::cout << e.what() << std::endl;
    	}
	}

	{
    	try {
    	    itChar = easyfind(vecChar, 'd');
    	    std::cout << "Found: " << *itChar << std::endl;
    	} catch (const std::runtime_error& e) {
    	    std::cout << e.what() << std::endl;
    	}
	}

    return 0;
}
