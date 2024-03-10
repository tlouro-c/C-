#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"

class ICharacter
{	
public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
protected:
	ICharacter( std::string name );
	std::string	_name;
	AMateria	*_materia[4] = {NULL, NULL, NULL, NULL};
	int			_numMateria = 0;
};


#endif

