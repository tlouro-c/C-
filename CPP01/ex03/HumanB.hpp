#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB{
public:
	void	attack( void );
	void	setWeapon( Weapon& newWeapon );
	HumanB( std::string name ):_name(name), _Weapon(NULL){};
private:
	std::string	_name;
	Weapon*		_Weapon;
};

#endif
