#include "Span.hpp"

int	main(void)
{
	int	maxSize;
	int	amountOfNumbers;
	std::srand(time(NULL));

	try 
	{
		std::cout << "Insert max size -> ";
		std::cin >> maxSize;
		if (std::cin.fail() || maxSize < 0)
			throw BadInput();
		std::cout << "Insert amount of random numbers -> ";
		std::cin.ignore();
		std::cin >> amountOfNumbers;
		if (std::cin.fail() || maxSize < 0)
			throw BadInput();
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}

	try
	{
		Span mySpanClass(maxSize);
		for (int i = 0; i < amountOfNumbers; i++)
			mySpanClass.addNumber(std::rand() % maxSize * 10);
		std::cout << mySpanClass;
		std::cout << "Shortest Span -> " << mySpanClass.shortestSpan() << std::endl;
		std::cout << "Longest Span -> " << mySpanClass.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "\nexception: " << e.what() << std::endl;
	}
}
