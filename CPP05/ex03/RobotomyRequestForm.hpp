#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <ctime>
# include <cstdlib> 
# include "Bureaucrat.hpp"

//? class Bureaucrat;

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( const RobotomyRequestForm& other );
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=( const RobotomyRequestForm& other );
	void execute(Bureaucrat const & executor) const;
private:
	RobotomyRequestForm( void );
	std::string const _target;
};

#endif
