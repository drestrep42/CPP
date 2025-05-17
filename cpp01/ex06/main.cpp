#include "Harl.hpp"

void	ft_exit(std::string error)
{
	std::cout << error << std::endl;
	_exit(0);
}

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
		ft_exit(USAGE_ERROR);
	harl.complain(argv[1]);
}
