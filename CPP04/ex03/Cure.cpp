#include "Cure.hpp"

Cure::Cure( void ) : AMateria( "cure" ) {}

Cure* Cure::clone( void ) const { return ( new Cure ); }

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}
