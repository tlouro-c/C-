#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat( void )
{
	std::cout << "Cat desctructor called" << std::endl;
}

void	Cat::makeSound ( void ) const
{
	std::cout << "meow" << std::endl;
}
