#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <algorithm>
# include <iostream>
# include <vector>

class OccorrenceNotFound : public std::exception {
	const char* what() const throw()
	{
		return ("exception: occorrence not found");
	}
};

template<typename T>
void	easyfind(const T& container, const int& occurence)
{
	if (std::find(container.begin(), container.end(), occurence) != container.end())
		std::cout << "occurrence was found!" << std::endl;
	else
		throw OccorrenceNotFound();
}

#endif
