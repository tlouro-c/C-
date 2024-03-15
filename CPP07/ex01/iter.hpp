#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template<typename T>
void	print(T& a)
{
	std::cout << a << std::endl;
}

template<typename T1, typename T2, typename T3>
void	iter(T1 arrayAddress, T2 arrayLength, T3 function)
{
	for (int i = 0; i < arrayLength; i++)
		function(arrayAddress[i]);
}



#endif
