#include "iter.hpp"
#include <iostream>
#include <string>


int main(void)
{
	int intArray[] = {1, 3, 4};

	iter(intArray, 3, print<int>);

	std::string *stringArray = new std::string[1];

	stringArray[0] = "Hello";

	iter(stringArray, 1, print<std::string>);
}
