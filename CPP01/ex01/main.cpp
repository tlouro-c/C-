#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );
Zombie* newZombie( std::string name );
void	randomChump( std::string name );

int	main(void)
{
	int	n;

	std::cout << "Set the size of the horde: ";
	std::cin >> n;
	Zombie* Horde = zombieHorde(n, "Alpha");
	for (int i = 0; i < n; i++)
		Horde[i].announce();
	std::cout << std::endl;
	delete[] Horde;
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

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie* Horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		Horde[i].SetName(name);
	return (Horde);
}
