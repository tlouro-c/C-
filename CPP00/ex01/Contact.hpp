#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <cctype>
	
class Contact{
public:
	std::string	GetFirstName()const {return firstName;}
	bool		SetFirstName(std::string newFirstName);
	std::string	GetLastName()const {return lastName;}
	bool		SetLastName(std::string newLastName);
	std::string	GetNickName()const {return nickName;}
	bool		SetNickName(std::string newNickame);
	std::string	GetPhoneNumber()const {return phoneNumber;}
	bool 		SetPhoneNumber(std::string newPhoneNumber);
	std::string	GetDarkestSecret()const {return darkestSecret;}
	bool		SetDarkestSecret(std::string newDarkestSecret);
	void		TruncateContact();
	Contact& operator= (const Contact& other);
private:
	std::string firstName;
	std::string lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
};

std::ostream& operator<< (std::ostream& out, const Contact &contact);

#endif
