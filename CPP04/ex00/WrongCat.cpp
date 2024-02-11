#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat desctructor called" << std::endl;
}

void	WrongCat::makeSound ( void ) const
{
	std::cout << "meow" << std::endl;
}
