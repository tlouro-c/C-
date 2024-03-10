#include "Bureaucrat.hpp"

int	main( void )
{
	std::cout << "Try to create a bureaucrat with grade lower than 150" << std::endl;
	try
	{
		Bureaucrat Rui( "Rui", 151);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n" << std::endl;
	}
	std::cout << "Try to create a bureaucrat with grade Higher than 1" << std::endl;
	try
	{
		Bureaucrat Ines( "Ines", 0);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n" << std::endl;
	}
	std::cout << "Try to create a valid bureaucrat" << std::endl;
	try
	{
		Bureaucrat Pedro( "Pedro", 150);
		std::cout << Pedro << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n" << std::endl;
	}
	std::cout << "Try to increment grade to less than 1" << std::endl;
	try
	{
		Bureaucrat Luis( "Luis", 1);
		Luis.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n" << std::endl;
	}
	std::cout << "Try to decrement grade to more than 150" << std::endl;
	try
	{
		Bureaucrat Pedro( "Pedro", 150);
		Pedro.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n" << std::endl;
	}
}
