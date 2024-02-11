#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog"), _brain(new Brain())
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog( void )
{
	delete(_brain);
	std::cout << "Dog desctructor called" << std::endl;
}

void	Dog::makeSound ( void ) const
{
	std::cout << "wuof" << std::endl;
}

Dog::Dog ( const Dog& copy ) : _brain(new Brain( (*copy._brain) )){}
