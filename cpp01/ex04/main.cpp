#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define USAGE_ERROR "Correct use: ./a.out filename s1 s2"
#define FILE_ERROR	"File does not exist or does not have valid permissions"

void	ft_exit(std::string error)
{
	std::cout << error << std::endl;
	_exit(1);
}

void	replace(std::ifstream &fd, std::string s1, std::string s2)
{
	std::ofstream			new_fd("new_file.txt");
	std::string				line;
	std::string				new_line;
	size_t					i;

	while (std::getline(fd, line))
	{
		i = 0;
		while (i < line.length())
		{
			if (line.substr(i, s1.length()) == s1)
			{
				new_fd << s2;
				i += s1.length();
			}
			else
				new_fd << line[i++];
		}
		new_fd << std::endl;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		ft_exit(USAGE_ERROR);
	std::ifstream	fd(argv[1]);
	if (!fd)
		ft_exit(FILE_ERROR);
	replace(fd, argv[2], argv[3]);
}
