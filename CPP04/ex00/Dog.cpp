#include "Dog.hpp"

void Dog::makeSound( void ) const
{
	std::cout << "Dog is barking..." << std::endl;
}

//* Canonical Mandatory

Dog::Dog( void ) : Animal( "Dog" )
{
	std::cout << "Dog Default Constructor Call" << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "Dog Default Destructor Call" << std::endl;
}

Dog::Dog( const Dog& other )
{
	*this = other;
	std::cout << "Dog Copy Constructor Call" << std::endl;
}

