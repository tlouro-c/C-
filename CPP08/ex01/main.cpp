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
	Span mySpanClass(maxSize);
	try
	{
		for (int i = 0; i < amountOfNumbers; i++)
			mySpanClass.addNumber(std::rand() % maxSize * 10);
		std::cout << mySpanClass << std::endl;
		std::cout << "Shortest Span -> " << mySpanClass.shortestSpan() << std::endl;
		std::cout << "Longest Span -> " << mySpanClass.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "\nexception: " << e.what() << std::endl;
		return (0);
	}

	std::cout << "\nTest for the betterAddNumber member function" << std::endl;
	std::vector<int> testVector;

	testVector.push_back(5);
	testVector.push_back(20);
	testVector.push_back(15);
	testVector.push_back(25);
	try
	{
		mySpanClass.betterAddNumber(testVector.begin(), testVector.end());
		std::cout << mySpanClass << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "\nexception: " << e.what() << std::endl;
	}
}


// //* Subject's main
// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0; 
// }
