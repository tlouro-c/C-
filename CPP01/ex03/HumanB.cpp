#include "HumanB.hpp"
#include "Weapon.hpp"

void	HumanB::setWeapon( Weapon& newWeapon )
{
	_Weapon = &newWeapon;
}

void	HumanB::attack( void )
{
	std::cout << _name << " attacks with their " << _Weapon->getType() << std::endl;
}

