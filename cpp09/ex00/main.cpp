#include "BitcoinExchange.hpp"

int main (int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " database" << std::endl;
		return 1;
	}

	BitcoinExchange exchange(argv[1]);
	exchange.run();

	return 0;
}
