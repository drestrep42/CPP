#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <numbers...>" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe pmergeMe(argv + 1, argv + argc);
		pmergeMe.print(false);
		pmergeMe.FordJohnson();
		pmergeMe.print(true);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
