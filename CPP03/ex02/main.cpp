#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void )
{
	ClapTrap	Wall_e( "Wall-e" );
	FragTrap	Eva( "Eva" );

	for (int i = 0; i <= 10; i++)
	{
		Wall_e.attack( "Eva" );
		Eva.takeDamage ( Wall_e.getAD() );
		Eva.beRepaired( 5 );
	}
	Wall_e.beRepaired( 100 );
	Wall_e.takeDamage ( 50 );

	Eva.attack( "Wall-e" );
	Wall_e.takeDamage( Eva.getAD() );
	Eva.highFivesGuys();
}
