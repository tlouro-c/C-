#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h> 

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int	main (void)
{
	Base *random = generate();
	std::cout << "Identify through pointer" << std::endl;
	identify(random);
	std::cout << "Identify through Reference" << std::endl;
	identify(*random);
	delete(random);
	return (0);
}


Base * generate(void)
{
	std::srand(time(NULL));
	int	index = std::rand() % 3;
	Base *options[] = {new A, new B, new C};
	Base *finalOption = options[index];

	for (int i = 0; (unsigned long)i < (sizeof(options) / sizeof(Base*)); i++)
	{
		if (options[i] != finalOption)
			delete(options[i]);
	}
	return (finalOption);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	Base dummy;
	try
	{
		dummy = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::bad_cast&) {}
	try
	{
		dummy = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::bad_cast&) {}
	try
	{
		dummy = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::bad_cast&) {}
}
