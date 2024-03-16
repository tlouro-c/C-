#include "Span.hpp"

int	main(void)
{
	int	maxSize;
	int	amountOfNumbers;
	std::srand(time(NULL));

	std::cout << "\nInsert max size -> ";
	std::cin >> maxSize;
	if (std::cin.fail())
		return (std::cout
			<< "Why are you trying to break me ? This is not even mandadory..." << std::endl, 1);
	std::cout << "Insert amount of random numbers -> ";
	std::cin.ignore();
	std::cin >> amountOfNumbers;
	if (std::cin.fail())
		return (std::cout
			<< "Why are you trying to break me ? This is not even mandadory..." << std::endl, 1);
	std::cout << std::endl;

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
