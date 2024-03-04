#include "Contact.hpp"

bool	Contact::SetFirstName(std::string newFirstName)
{
	if (newFirstName.empty())
		return (false);
	for (int i = 0; newFirstName[i]; i++)
	{
		if (!std::isspace(newFirstName[i]))
		{
			firstName = newFirstName;
			return (true);
		}
	}
	return (false);
}

bool	Contact::SetLastName(std::string newLastName)
{
	if (newLastName.empty())
		return (false);
	for (int i = 0; newLastName[i]; i++)
	{
		if (!std::isspace(newLastName[i]))
		{
			lastName = newLastName;
			return (true);
		}
	}
	return (false);
}

bool	Contact::SetNickName(std::string newNickName)
{
	if (newNickName.empty())
		return (false);
	for (int i = 0; newNickName[i]; i++)
	{
		if (!std::isspace(newNickName[i]))
		{
			nickName = newNickName;
			return (true);
		}
	}
	return (false);
}

bool	Contact::SetDarkestSecret(std::string newDarkestSecret)
{
	if (newDarkestSecret.empty())
		return (false);
	for (int i = 0; newDarkestSecret[i]; i++)
	{
		if (!std::isspace(newDarkestSecret[i]))
		{
			darkestSecret = newDarkestSecret;
			return (true);
		}
	}
	return (false);
}

bool	Contact::SetPhoneNumber(std::string newPhoneNumber)
{
	if (newPhoneNumber.empty())
		return (false);
	for (int i = 0; newPhoneNumber[i]; i++)
	{
		if (!isdigit(newPhoneNumber[i]))
			return (false);
	}
	phoneNumber = newPhoneNumber;
	return (true);
}

void Contact::TruncateContact()
{
	if (firstName.length() > 10){
		firstName.resize(10); firstName[9] = '.';}
	if (lastName.length() > 10){
		lastName.resize(10); lastName[9] = '.';}
	if (nickName.length() > 10){
		nickName.resize(10); nickName[9] = '.';}
	if (phoneNumber.length() > 10){
		phoneNumber.resize(10); phoneNumber[9] = '.';}
	if (darkestSecret.length() > 10){
		darkestSecret.resize(10); darkestSecret[9] = '.';}
}

std::ostream& operator<< (std::ostream& out, const Contact &contact)
{
	out << "First Name: " << contact.GetFirstName() << std::endl;
	out << "Last Name: " << contact.GetLastName() << std::endl;
	out << "Nickname: " << contact.GetNickName() << std::endl;
	out << "Phone Number: " << contact.GetPhoneNumber() << std::endl;
	out << "Darkest Secret: " << contact.GetDarkestSecret() << " (:o)" << std::endl;
	return (out);
}

Contact& Contact::operator= (const Contact& other)
{
	firstName = other.firstName;
	lastName = other.lastName;
	nickName = other.nickName;
	phoneNumber = other.phoneNumber;
	darkestSecret = other.darkestSecret;
	return *this;
}


