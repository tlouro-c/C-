#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>
# include "Bureaucrat.hpp"

//? class Bureaucrat;

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( const ShrubberyCreationForm& other );
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other );
	void execute(Bureaucrat const & executor) const;
private:
	ShrubberyCreationForm( void );
	std::string const _target;
};

#endif
