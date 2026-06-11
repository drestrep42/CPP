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
		std::deque<int> nbrs;
		for (char **it = argv + 1; it != argv + argc; ++it)
		{
			int nbr = std::atoi(*it);
			if (nbr < 0)
				throw std::invalid_argument("Negative numbers are not allowed");
			nbrs.push_back(nbr);
		}

		printDeque(nbrs, false);
		const std::clock_t start = std::clock();
		FordJohnson(nbrs);
		const std::clock_t end = std::clock();
		printDeque(nbrs, true);
		const double elapsedUs = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
		std::cout << "Time to process a range of " << (argc - 1)
			<< " elements with std::deque: " << elapsedUs / 1000.0 << " ms" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	try
	{
		std::vector<int> nbrs;
		for (char **it = argv + 1; it != argv + argc; ++it)
		{
			int nbr = std::atoi(*it);
			if (nbr < 0)
				throw std::invalid_argument("Negative numbers are not allowed");
			nbrs.push_back(nbr);
		}

		printVector(nbrs, false);
		const std::clock_t start = std::clock();
		FordJohnsonVector(nbrs);
		const std::clock_t end = std::clock();
		printVector(nbrs, true);
		const double elapsedUs = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
		std::cout << "Time to process a range of " << (argc - 1)
			<< " elements with std::vector: " << elapsedUs / 1000.0 << " ms" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
