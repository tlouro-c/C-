#include "PhoneBook.hpp"

void	PhoneBook::AddContact()
{
	Contact		newContact;
	std::string	tmp;
	
	while (!newContact.SetFirstName(tmp))
		std::cout << "First Name: ", std::getline(std::cin, tmp);
	tmp.clear();
	while (!newContact.SetLastName(tmp))
		std::cout << "Last Name: ", std::getline(std::cin, tmp);
	tmp.clear();
	while (!newContact.SetNickName(tmp))
		std::cout << "Nickname: ", std::getline(std::cin, tmp);
	tmp.clear();
	while (!newContact.SetPhoneNumber(tmp))
		std::cout << "Phone Number: ", std::getline(std::cin, tmp);
	tmp.clear();
	while (!newContact.SetDarkestSecret(tmp))
		std::cout << "Darkest Secret: ", std::getline(std::cin, tmp);
	contacts[(addedContacts + 8) % 8] = newContact;
	addedContacts++;
}

Contact	PhoneBook::SearchByIndex(const int index) const
{
	if (index > addedContacts || index > 8 || index < 1)
		return Contact();
	return (contacts[index - 1]);
}

std::ostream& operator<< (std::ostream &out, const PhoneBook& phonebook)
{
	Contact tmp;

	out << std::endl << "          _________________________" << std::endl;
	out << "          | PhoneBook for Brokies |" << std::endl;
	out << "          ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
	out << "_____________________________________________" << std::endl;
	out << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
	for (int i = 1, nrContacts = phonebook.GetTotalAddedContacts() + 1; i < 9 && i < nrContacts; i++)
	{
		tmp = phonebook.SearchByIndex(i);
		tmp.TruncateContact();
		out << "|" << std::right << std::setw(10) << i;
		out << "|" 	<< std::right << std::setw(10) << tmp.GetFirstName();
		out << "|" 	<< std::right << std::setw(10) << tmp.GetLastName();
		out << "|" 	<< std::right << std::setw(10) << tmp.GetNickName() << "|" << std::endl;
	}
	out << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
	return out;
}

