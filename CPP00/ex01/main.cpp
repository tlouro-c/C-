#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdio>
#include <cstdlib>


int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;
	std::string	index;

	while (input != "EXIT")
	{
		std::cout << std::endl<< "Use ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.AddContact();
		else if (input == "SEARCH")
		{
			std::cout << phonebook;
			std::cout << "Input an index: ";
			std::getline(std::cin, index);
			if (std::atoi(index.c_str()) > phonebook.GetTotalAddedContacts() 
				|| std::atoi(index.c_str()) > 8 
				|| std::atoi(index.c_str()) < 1)
				std::cerr << "Index out of range..." << std::endl;
			else
				std::cout << std::endl << phonebook.SearchByIndex(std::atoi(index.c_str())) << std::endl;
		}
	}
	std::cout << "Bye :c" << std::endl;
	return (0);
}

