#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <chrono>
#include <thread>

void	OpeningPhonebook();

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;
	int			index;

	OpeningPhonebook();
	while (input != "EXIT")
	{
		fflush(stdin);
		std::cout << std::endl<< "Use ADD, SEARCH or EXIT" << std::endl;
		std::cin >> input;
		if (input == "ADD")
			phonebook.AddContact();
		else if (input == "SEARCH")
		{
			std::cout << phonebook;
			std::cout << "Input an index: ";
			std::cin >> index;
			if (index > phonebook.GetTotalAddedContacts() || index > 8 || index < 1)
				std::cerr << "Index out of range..." << std::endl;
			else
				std::cout << std::endl << phonebook.SearchByIndex(index) << std::endl;
		}
	}
	std::cout << "Bye :c" << std::endl;
	return (0);
}

void	OpeningPhonebook()
{
	std::cout << "Opening Phonebook" << std::flush;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "." << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "." << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "." << std::endl;
}
