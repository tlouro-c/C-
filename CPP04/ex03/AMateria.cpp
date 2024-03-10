#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type( type ) {}

std::string const & AMateria::getType( void ) const { return (_type);}

AMateria::AMateria( const AMateria& other )
{
	*this = other;
}

AMateria& AMateria::operator=( const AMateria &other )
{
}

