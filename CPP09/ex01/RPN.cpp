#include "RPN.hpp"

void	ReversePolishNotationCalculator(__intStack& stack, std::string& expression)
{
	int	result = 0;
	for (std::string::iterator it = expression.begin(); it != expression.end(); it++)
	{
		if (std::isdigit(*it)) {
			stack.push(static_cast<int>(*it - '0')); }
		else if (*it != ' ')
		{ 
			if (stack.size() < 2)
				throw (1);
			result = PerformOperation(PeekAndPop(stack), PeekAndPop(stack), *it);
			//std::cout << "\t" << result << std::endl;
			stack.push(result);
		}
	}
	if (stack.size() > 1)
		throw (1);
	std::cout << "Result: " << result << std::endl;
}

int	PerformOperation(int a, int b, char c)
{
	//std::cout << b << ' ' << c << ' ' << a << std::endl;
	if (c == '+') 
		return (b + a);
	else if (c == '-')
		return (b - a);
	else if (c == '/') { if (a == 0) { throw "Division by 0 not supported"; }
		return (b / a); }
	else
		return (b * a);
}


inline int	PeekAndPop(__intStack& stack)
{
	int	top = stack.top();
	return (stack.pop(), top);
}

bool spaceSeparated(std::string expression)
{
	for (int i = 0; i < static_cast<int>(expression.size() - 1); i ++) {
		if (!std::isspace(expression[i]) && !std::isspace(expression[i + 1])) { std::cout << "Parsing" << std::endl;
			return (false); }
	}
	return (true);
}
