#include "Animal.hpp"

Animal::Animal ( std::string type) : _type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal ( void )
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal ( void )
{
	std::cout << "Generic Animal destructor called" << std::endl;
}

Animal::Animal ( const Animal& other )
{
	this->_type = other._type;
}

Animal& Animal::operator=( const Animal& other )
{
	this->_type = other._type;
	return *this;
}
