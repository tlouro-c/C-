#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() 
{
	Animal* animals[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		animals[i]->makeSound();
		delete(animals[i]);
	}
	return 0; 
}
