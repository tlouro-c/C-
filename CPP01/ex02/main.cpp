#include <iostream>
#include <string>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	char*	stringPTR = reinterpret_cast<char *>(&string);
	std::string&	stringREF = string;

	std::cout << "Memory address of the string variable: " << &string << std::endl;
	std::cout << "Memory address held by stringPTR: " << static_cast<void*>(stringPTR) << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl << std::endl;

	std::cout << "Value of the string variable: " << string << std::endl;
	std::cout << "Value pointed to by stringPTR: " << stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
}
