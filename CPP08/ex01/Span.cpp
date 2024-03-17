#include "Span.hpp"

int		Span::shortestSpan()
{
	if (_classVector.size() < 2)
		throw NotEnoughIntegers();
	std::vector<int> tmp = _classVector;
	std::sort(tmp.begin(), tmp.end());
	int	shortestSpan = INT_MAX;
	for (std::vector<int>::iterator it = tmp.begin() + 1;
		it != tmp.end(); it++)
	{
		if (*it - *(it - 1) < shortestSpan)
			shortestSpan = *it - *(it - 1);
	}
	return (shortestSpan);
}

int		Span::longestSpan()
{
	if (_classVector.size() < 2)
		throw NotEnoughIntegers();
	std::vector<int> tmp = _classVector;
	std::sort(tmp.begin(), tmp.end());
	return (*(tmp.end() - 1) - *tmp.begin());
}

void	Span::addNumber(int number)
{
	if (_classVector.size() >= _maxSize)
		throw NoRemainingSpace();
	_classVector.push_back(number);
}

Span::Span(uint maxSize) 
{
	_maxSize = maxSize;
}

Span::~Span()
{
}

Span::Span(const Span& other)
{
	if (this != &other)
		*this = other;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_classVector = other._classVector;
		_maxSize = other._maxSize;
	}
	return (*this);
}

void	Span::print(std::ostream& os)
{
	int	i = 0;
	for (std::vector<int>::iterator it = _classVector.begin()
		; it != _classVector.end(); it++)
		os << "[" << i++ << "] -> " << *it << "\n";
	if (i == 0)
		std::cout << "empty" << std::endl;
	os << std::endl;
}

std::ostream& operator<<(std::ostream& os, Span& span)
{
	span.print(os);
	return (os);
}
