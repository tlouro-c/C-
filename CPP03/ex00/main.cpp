#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	Wall_e( "Wall-e" );

	for (int i = 0; i <= 10; i++)
		Wall_e.attack( "Eva" );
	Wall_e.beRepaired( 100 );
	Wall_e.takeDamage ( 50 );
}
