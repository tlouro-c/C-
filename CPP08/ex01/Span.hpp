#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <string>
# include <algorithm>
# include <climits>
# include <iostream>
# include <ctime>

typedef unsigned int uint;

class Span {
public:
	Span(uint maxSize);
	~Span();
	Span(const Span& other);
	Span& operator=(const Span& other);

	void	addNumber(int number);
	void	betterAddNumber(std::vector<int>::iterator begin,
				std::vector<int>::iterator end);
	int		shortestSpan();
	int		longestSpan();
	void	print(std::ostream& os);

private:
	std::vector<int>	_classVector;
	uint				_maxSize;
	Span();

	class NoRemainingSpace : public std::exception {
	public:
		const char* what() const throw()
		{
			return ("no remaining space");
		}
	};
	class NotEnoughIntegers : public std::exception {
	public:
		const char* what() const throw()
		{
			return ("not enough integers");
		}
	};
};

std::ostream& operator<<(std::ostream& os, Span& span);

class BadInput : public std::exception {
public:
	const char* what() const throw()
	{
		return ("Why are you trying to break me ? This is not even mandadory...");
	}
};

#endif
