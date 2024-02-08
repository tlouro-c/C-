#include "Weapon.hpp"

void	Weapon::setType( std::string newType )
{
	_type = newType;
}

const std::string& Weapon::getType( void )const
{
	return _type;
}

Weapon& Weapon::operator= ( const Weapon& newWeapon )
{
	setType(newWeapon.getType());
	return *this;
}
