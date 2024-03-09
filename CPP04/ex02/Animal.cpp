#include "Animal.hpp"

std::string Animal::getType( void ) const
{
	return (_type);
}

Animal::Animal( std::string type ) : _type( type)
{
	std::cout << "Generic Animal Type Constructor Call" << std::endl;
}

//* Canonical Mandatory

Animal::Animal( void ) : _type("Generic Animal")
{
	std::cout << "Generic Animal Default Constructor Call" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Generic Animal Default Destructor Call" << std::endl;
}

Animal::Animal( const Animal& other)
{
	*this = other;
	std::cout << "Generic Animal Copy Constructor Call" << std::endl;
}

Animal& Animal::operator=( const Animal& other)
{
	_type = other._type;
	return (*this);
}
