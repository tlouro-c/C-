#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main( void )
{
	Animal *animals[10];
	Dog Dog1;
	Dog Dog2;

	std::cout << std::endl;

	for (int i = 0; static_cast<unsigned long>(i) < sizeof(animals) / sizeof(Animal*); i++)
	{
		if (static_cast<unsigned long>(i) < (sizeof(animals) / sizeof(Animal*)) / 2)
			animals[i] = new Dog;
		else
			animals[i] = new Cat;
	}

	std::cout << std::endl;

	for (int i = 0; static_cast<unsigned long>(i) < sizeof(animals) / sizeof(Animal*); i++)
		delete animals[i];

	std::cout << std::endl;
	
	std::cout << "Test for Shallow vs Deep Copies" << std::endl; //* Shallow Copies would copy the pointers while Deep copies will copy the content of the pointers
	Dog1.setIdea(0, "I have an idea");
	Dog2 = Dog1;
	std::cout << "Dog2's mind -> " << Dog2.getIdea(0) << std::endl;
	Dog2.setIdea(0, "I changed my mind");
	std::cout << "Dog1's mind -> " << Dog1.getIdea(0) << std::endl;
	return (0);
}
