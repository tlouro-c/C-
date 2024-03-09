#include "Brain.hpp"

void Brain::setIdea( int index, std::string idea)
{
	if (index < 0 || static_cast<unsigned long>(index) >= sizeof(_ideas) / sizeof(std::string))
		return ;
	_ideas[index] = idea;
}

std::string Brain::getIdea( int index )
{
	if (index < 0 || static_cast<unsigned long>(index) >= sizeof(_ideas) / sizeof(std::string))
		return (static_cast<std::string>("\0"));
	return (_ideas[index]);
}

//* Canonical Mandatory

Brain::Brain( void )
{
	std::cout << "Brain Default Constructor Call" << std::endl;
}

Brain::~Brain ( void )
{
	std::cout << "Brain Default Destructor Call" << std::endl;
}

Brain::Brain ( const Brain& other )
{
	*this = other;
	std::cout << "Brain Copy Constructor Call" << std::endl;
}

Brain& Brain::operator=( const Brain& other)
{
	for (int i = 0; static_cast<unsigned long>(i) < sizeof(other._ideas) / sizeof(std::string); i++)
		this->_ideas[i] = other._ideas[i];
	return (*this);
}	
