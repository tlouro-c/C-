#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class AMateria {
public:
	AMateria( std::string const & type );
	AMateria( const AMateria& other );
	AMateria& operator=( const AMateria &other );
	virtual ~AMateria ( void ) {};
	std::string const & getType( void ) const; //Returns the materia type
	virtual AMateria* clone( void ) const = 0;
	virtual void use( ICharacter& target ) = 0;
protected:
	std::string _type;
};

#endif
