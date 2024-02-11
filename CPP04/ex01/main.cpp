#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() 
{
	Animal* animals[10];
	Animal	*copy;

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	copy = new Animal(*animals[5]);
	delete (copy);
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		delete(animals[i]);
	return 0; 
}
