#include "Harl.hpp"

int	main(int argc, char *argv[] )
{
	Harl	harl;

	if (argc != 2)
		return (std::cerr << "Invalid number of arguments" << std::endl, 1);
	std::cout << std::endl;
	harl.complain(argv[1]);
	std::cout << std::endl;
}
