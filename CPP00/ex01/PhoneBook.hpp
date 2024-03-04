#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class PhoneBook{
public:
	void	AddContact();
	int		GetTotalAddedContacts()const {return addedContacts;}
	Contact	SearchByIndex(int index)const;
private:
	static int		addedContacts;
	Contact contacts[8];
};

std::ostream& operator<< (std::ostream &out, const PhoneBook& phonebook);

#endif
