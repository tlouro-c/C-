#include "MutantStack.hpp"
#include <vector>
#include <iostream>

int	main(void)
{
	MutantStack<int> myStack;

	myStack.push(5);
	myStack.push(10);
	myStack.push(3);
	myStack.push(0);

	std::cout << "Top -> " <<  myStack.top() << std::endl;

	std::cout << "\nSize -> " <<  myStack.size() << std::endl;

	MutantStack<int>::iterator it;

	std::cout << "\nIterating over the stack using an iterator" << std::endl;
	for (it = myStack.begin(); it != myStack.end(); it++)
		std::cout << *it << std::endl;

}

// //* Subject's main
// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);

// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite) {
// 	std::cout << *it << std::endl;
// 	++it; }
// 	std::stack<int> s(mstack); return 0;
// }
