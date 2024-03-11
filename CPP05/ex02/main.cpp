#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void )
{
	AForm *Forms[3] = {};

	std::cout << "Try to sign and execute forms using the methods from the AForm Class\n" << std::endl;
	try
	{
		Bureaucrat Luis ("Luis", 130);
		Forms[0] = new ShrubberyCreationForm( "Office" );
		Forms[1] = new RobotomyRequestForm( "Home" );
		Forms[2] = new PresidentialPardonForm( "School" );
		for (int i = 0; i < 3; i++)
		{
			Forms[i]->beSigned(Luis);
			std::cout << Forms[i]->getName() << "was signed." << std::endl; 
			Forms[i]->execute(Luis);
			std::cout << Forms[i]->getName() << "was executed." << std::endl; 
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	for (int i = 0; i < 3 && Forms[i]; i++){
			delete(Forms[i]); Forms[i] = NULL;}
	std::cout << "-----------\n" << std::endl;
	std::cout << "Try to sign and execute forms using the methods from the Bureaucrat Class\n" << std::endl;
	try
	{
		Bureaucrat Luis ("Luis", 145);
		Forms[0] = new ShrubberyCreationForm( "Office" );
		Forms[1] = new RobotomyRequestForm( "Home" );
		Forms[2] = new PresidentialPardonForm( "School" );
		for (int i = 0; i < 3; i++)
		{
			Luis.signAForm(*Forms[i]);
			Luis.executeForm(*Forms[i]);
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	for (int i = 0; i < 3 && Forms[i]; i++){
			delete(Forms[i]); Forms[i] = NULL;}
}
