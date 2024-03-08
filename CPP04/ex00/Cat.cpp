#include "Cat.hpp"

void Cat::makeSound( void ) const
{
	std::cout << "Cat is purring..." << std::endl;
}

//* Canonical Mandatory

Cat::Cat( void ) : Animal( "Cat" )
{
	std::cout << "Cat Default Constructor Call" << std::endl;
}

Cat::~Cat( void )
{
	std::cout << "Cat Default Destructor Call" << std::endl;
}

Cat::Cat( const Cat& other)
{
	*this = other;
	std::cout << "Cat Copy Constructor Call" << std::endl;
}
