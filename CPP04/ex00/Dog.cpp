#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "Dog desctructor called" << std::endl;
}

void	Dog::makeSound ( void ) const
{
	std::cout << "wuof" << std::endl;
}
