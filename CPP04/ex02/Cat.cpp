#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat"), _brain(new Brain())
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat( void )
{
	delete(_brain);
	std::cout << "Cat desctructor called" << std::endl;
}

void	Cat::makeSound ( void ) const
{
	std::cout << "meow" << std::endl;
}

Cat::Cat ( const Cat& copy ) : _brain(new Brain( (*copy._brain) )){}

