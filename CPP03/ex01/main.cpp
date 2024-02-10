#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	ClapTrap	Wall_e( "Wall-e" );
	ScavTrap	Eva( "Eva" );

	for (int i = 0; i <= 10; i++)
	{
		Wall_e.attack( "Eva" );
		Eva.takeDamage ( Wall_e.getAD() );
	}
	Wall_e.beRepaired( 100 );
	Wall_e.takeDamage ( 50 );

	Eva.guardGate();
}
