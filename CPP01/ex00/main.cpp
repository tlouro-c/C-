#include "Zombie.hpp"

int	main(void)
{
	Zombie *Alpha = newZombie("Alpha");
	randomChump("Beta");
	delete(Alpha);
}
