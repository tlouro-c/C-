#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Invalid nr. of arguments." << std::endl, 1);
	(void)argc;
	ScalarConverter::convert(argv[1]);
}
