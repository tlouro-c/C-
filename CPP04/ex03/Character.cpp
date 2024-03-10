#include "Character.hpp"

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	if (_numMateria >= 4)
		return ;
	_materia[_numMateria] = m;
	
}

void Character::unequip(int idx)
{
	if (_numMateria <= 0 || idx + 1 > _numMateria)
		return ;
	_materia[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (_numMateria <= 0 || idx + 1 > _numMateria)
		return ;
	_materia[idx]->use(target);
}

Character::Character ( std::string _name ) : ICharacter( _name ) {};

