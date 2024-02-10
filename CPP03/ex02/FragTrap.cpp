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

