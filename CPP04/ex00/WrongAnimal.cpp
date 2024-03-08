#include "WrongAnimal.hpp"

void WrongAnimal::makeSound( void ) const
{
	std::cout << "Generic WrongAnimal Sound" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
	return (_type);
}

WrongAnimal::WrongAnimal( std::string type ) : _type( type)
{
	std::cout << "Generic WrongAnimal Type Constructor Call" << std::endl;
}

//* Canonical Mandatory

WrongAnimal::WrongAnimal( void ) : _type("Generic WrongAnimal")
{
	std::cout << "Generic WrongAnimal Default Constructor Call" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "Generic WrongAnimal Default Destructor Call" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other)
{
	*this = other;
	std::cout << "Generic WrongAnimal Copy Constructor Call" << std::endl;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other)
{
	_type = other._type;
	return (*this);
}
