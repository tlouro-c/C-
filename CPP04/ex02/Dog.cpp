#include "Dog.hpp"
#include "Brain.hpp"

void Dog::setIdea( int index, std::string idea)
{
	_brain->setIdea(index, idea);
}

std::string Dog::getIdea( int index ) const
{
	return (_brain->getIdea(index));
}

void Dog::makeSound( void ) const
{
	std::cout << "Dog is barking..." << std::endl;
}

//* Canonical Mandatory

Dog::Dog( void ) : Animal( "Dog" ), _brain ( new Brain )
{
	std::cout << "Dog Default Constructor Call" << std::endl;
}

Dog::~Dog( void )
{
	delete _brain;
	std::cout << "Dog Default Destructor Call" << std::endl;
}

Dog::Dog( const Dog& other )
{
	*this = other;
	std::cout << "Dog Copy Constructor Call" << std::endl;
}

Dog& Dog::operator=( const Dog& other)
{
	this->_type = other._type;
	*this->_brain = *other._brain;
	return (*this);
}

