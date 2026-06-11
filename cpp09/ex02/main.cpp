#include "PmergeMe.hpp"
#include <ctime>

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
		const std::clock_t start = std::clock();
		pmergeMe.print(false);
		pmergeMe.FordJohnson();
		pmergeMe.print(true);
		const std::clock_t end = std::clock();
		const double elapsedUs = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
		std::cout << "Time to process a range of " << (argc - 1)
			<< " elements with std::deque: " << elapsedUs << " us" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
