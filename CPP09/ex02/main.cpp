#include "PmergeMe.hpp"

int	main(int argc, char** argv)
{
	std::vector<int>	myVector;
	std::list<int>		myList;
	clock_t				sV, sL, eV, eL;

	try {
		fillContainers(myVector, myList, argc, argv); }
	catch (const char* errorMessage) {
		std::cout << errorMessage << std::endl;
		return (1);
	}
	printContainer(myVector.begin(), myVector.end(), "Before:");
	sV = std::clock();
	fordJohnsonSort<std::vector<int>, PairsVector>(myVector);
	eV = std::clock();
	printContainer(myVector.begin(), myVector.end(), "After:");

	sL = std::clock();
	fordJohnsonSort<std::list<int>, PairsList>(myList);
	eL = std::clock();

	std::cout << "Time to process a range of " << argc - 1 << 
		" elements with std::vector : " << timeSinceInUs(sV, eV) << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << 
		" elements with std::list : " << timeSinceInUs(sL, eL) << " us" << std::endl;
	return (0);
}
