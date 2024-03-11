#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main( void )
{
	Intern JJ;
	AForm *newForm;

	newForm = JJ.makeForm("PresidentialPardonForm", "Office");
	try
	{
		Bureaucrat Luis( "Luis", 4);
		std::cout << Luis << std::endl;
		std::cout << *newForm << std::endl;
		newForm->beSigned(Luis);
		newForm->execute(Luis);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete (newForm);
	return (0);
}
