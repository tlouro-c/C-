#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> intVector;

	intVector.emplace_back(5);
	intVector.emplace_back(2);
	intVector.emplace_back(9);
	try
	{
		easyfind(intVector, 5);
		easyfind(intVector, 24);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
