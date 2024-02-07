#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
			std::cout << static_cast<char>(toupper(argv[i][j]));
	}
	std::cout << std::endl;
}
