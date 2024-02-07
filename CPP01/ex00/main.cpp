#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

int	main(void)
{
	Zombie * Alpha = newZombie("Alpha");
	randomChump("Beta");
	delete(Alpha);
}

Zombie* newZombie( std::string name )
{
	Zombie *newZombie = new Zombie(name);
	newZombie->announce();
	return (newZombie);
}

void	randomChump( std::string name )
{
	Zombie	newZombie(name);

	newZombie.announce();
}
