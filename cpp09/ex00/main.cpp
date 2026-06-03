#include "BitcoinExchange.hpp"

int main (int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " input_file" << std::endl;
		return 1;
	}

	BitcoinExchange exchange;
	exchange.run(argv[1]);

	return 0;
}
