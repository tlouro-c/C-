#include "Array.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	{
		Array<int> intArray(10);

		std::cout << "Array<int> size: " << intArray.size() << std::endl;
		try
		{
			intArray[5] = 9;
			std::cout << intArray[5] << std::endl;
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		Array<std::string> stringArray(5);

		std::cout << "Array<std::string> size: " << stringArray.size() << std::endl;
		try
		{
			stringArray[4] = "Hello World!";
			std::cout << stringArray[4] << std::endl;
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
	}
	return (0);
}
