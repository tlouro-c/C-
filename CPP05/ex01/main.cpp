#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void )
{
	std::cout << "Try to create a Form with sign grade lower than 150" << std::endl;
	try
	{
		Form PeaceAgreement( "Peace Agreement", 151, 150);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n" << std::endl;
	}
	std::cout << "Try to create a Form with sign grade higher than 1" << std::endl;
	try
	{
		Form PeaceAgreement( "Peace Agreement", 0, 150);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n" << std::endl;
	}
	std::cout << "Create a valid form and bureaucrat and try to sign the form" << std::endl;
	try
	{
		Bureaucrat Pedro( "Pedro", 150);
		Form	PeaceAgreement( "Peace Agreement", 5, 1);
		std::cout << Pedro;
		std::cout << PeaceAgreement;
		Pedro.signForm(PeaceAgreement);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n" << std::endl;
	}
	std::cout << "Sign a Grade" << std::endl;
	try
	{
		Bureaucrat	Luis( "Luis", 1);
		Form		PeaceAgreement( "Peace Agreement", 5, 1);
		std::cout << Luis;
		std::cout << PeaceAgreement;
		Luis.signForm(PeaceAgreement);
		std::cout << PeaceAgreement;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n" << std::endl;
	}
}
