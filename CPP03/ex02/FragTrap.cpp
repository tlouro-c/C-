#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap Constructor Called" << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap Destructor Called" << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	std::cout << "(High Five Everyone)" << std::endl;
}

void FragTrap::attack( const std::string& target )
{
		if (_energyPoints > 0)
	{
		std::cout << "FragTrap "
				<< _name 
				<< " attacks "
				<< target
				<< ", causing "
				<<  _attackDamage 
				<< " points of damage!" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "FragTrap "
				<< _name 
				<< " doesn't have enough energy" << std::endl;
}

