#include "HumanB.hpp"
#include "Weapon.hpp"

void	HumanB::setWeapon( Weapon& newWeapon )
{
	_Weapon = &newWeapon;
}

void	HumanB::attack( void )
{
	if (_Weapon)
		std::cout << _name << " attacks with their " << _Weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon" << std::endl;
}

