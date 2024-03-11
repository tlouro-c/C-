#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <ctime>
# include "Bureaucrat.hpp"

//? class Bureaucrat;

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( const PresidentialPardonForm& other );
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=( const PresidentialPardonForm& other );
	void execute(Bureaucrat const & executor) const;
private:
	PresidentialPardonForm( void );
	std::string const _target;
};

#endif
