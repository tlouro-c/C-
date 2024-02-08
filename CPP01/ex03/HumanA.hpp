#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA{
public:
	void	attack( void );
	HumanA( std::string name, Weapon& Weapon ):_name(name), _Weapon(Weapon){};
private:
	std::string	_name;
	Weapon&		_Weapon;
};

#endif
