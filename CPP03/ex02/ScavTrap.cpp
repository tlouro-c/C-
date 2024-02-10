#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

void ScavTrap::attack( const std::string& target )
{
	if (_energyPoints > 0)
	{
		std::cout << "ScavTrap "
				<< _name 
				<< " attacks "
				<< target
				<< ", causing "
				<<  _attackDamage 
				<< " points of damage!" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "ScavTrap "
				<< _name 
				<< " doesn't have enough energy" << std::endl;
}

void ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
