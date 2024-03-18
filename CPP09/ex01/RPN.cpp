#include "RPN.hpp"

void	ReversePolishNotationCalculator(__intStack& stack, std::string& expression)
{
	int	result = 0;
	std::cout << expression << std::endl;
	for (std::string::iterator it = expression.begin(); it != expression.end(); it++)
	{
		if (std::isdigit(*it)) {
			stack.push(static_cast<int>(*it - '0')); }
		else if (*it != ' ')
		{ 
			if (stack.size() < 2)
				throw (1);
			result = PerformOperation(PeekAndPop(stack), PeekAndPop(stack), *it);
			stack.push(result);
		}
	}
	std::cout << "Result: " << result << std::endl;
}

int	PerformOperation(int a, int b, char c)
{
	if (c == '+') 
		return (b + a);
	else if (c == '-')
		return (b - a);
	else if (c == '/')
		return (b / a);
	else
		return (b * a);
}


inline int	PeekAndPop(__intStack& stack)
{
	int	top = stack.top();
	return (stack.pop(), top);
}
