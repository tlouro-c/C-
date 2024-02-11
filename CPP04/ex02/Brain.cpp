#include "Brain.hpp"

Brain::Brain ( void )
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain ( const Brain& other )
{
	for (int i = 0; i < static_cast<int>(sizeof(_ideas) / sizeof(*_ideas)); i++)
		_ideas[i] = other._ideas[i];
}

Brain::~Brain ( void )
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=( const Brain& other)
{
	for (int i = 0; i < static_cast<int>(sizeof(_ideas) / sizeof(*_ideas)); i++)
		_ideas[i] = other._ideas[i];
	return *this;
}
