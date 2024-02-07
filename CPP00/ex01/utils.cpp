#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <chrono>
#include <thread>

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

