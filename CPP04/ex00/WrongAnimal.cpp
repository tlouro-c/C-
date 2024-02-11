#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal ( std::string type) : _type(type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal ( void )
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal ( void )
{
	std::cout << "Generic WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::makeSound ( void ) const
{
	std::cout << "Generic WrongAnimal Sound" << std::endl; 
}
