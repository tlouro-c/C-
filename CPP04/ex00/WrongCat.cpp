#include "WrongCat.hpp"

void WrongCat::makeSound( void ) const
{
	std::cout << "WrongCat is purring..." << std::endl;
}

//* Canonical Mandatory

WrongCat::WrongCat( void ) : WrongAnimal( "WrongCat" )
{
	std::cout << "WrongCat Default Constructor Call" << std::endl;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat Default Destructor Call" << std::endl;
}

WrongCat::WrongCat( const WrongCat& other)
{
	*this = other;
	std::cout << "WrongCat Copy Constructor Call" << std::endl;
}
