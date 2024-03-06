#include "Zombie.hpp"

int	main(void)
{
	int	n;

	std::cout << "Set the size of the horde: ";
	std::cin >> n;
	Zombie* Horde = zombieHorde(n, "Alpha");
	if (!Horde)
		return (std::cerr << "Error" << std::endl, 1);
	for (int i = 0; i < n; i++)
		Horde[i].announce();
	std::cout << std::endl;
	delete[] Horde;
}
