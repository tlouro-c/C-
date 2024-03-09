#include "Cat.hpp"

void Cat::setIdea( int index, std::string idea)
{
	_brain->setIdea(index, idea);
}

std::string Cat::getIdea( int index ) const
{
	return (_brain->getIdea(index));
}

void Cat::makeSound( void ) const
{
	std::cout << "Cat is purring..." << std::endl;
}

//* Canonical Mandatory

Cat::Cat( void ) : Animal( "Cat" ), _brain( new Brain )
{
	std::cout << "Cat Default Constructor Call" << std::endl;
}

Cat::~Cat( void )
{
	delete _brain;
	std::cout << "Cat Default Destructor Call" << std::endl;
}

Cat::Cat( const Cat& other)
{
	*this = other;
	this->_brain = other._brain;
	std::cout << "Cat Copy Constructor Call" << std::endl;
}

Cat& Cat::operator=( const Cat& other)
{
	this->_type = other._type;
	*this->_brain = *other._brain;
	return (*this);
}
