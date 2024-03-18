#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>
# include <algorithm>
# include <cctype>

typedef std::stack<int> __intStack;

void	ReversePolishNotationCalculator(__intStack& stack, std::string& expression);
int		PeekAndPop(__intStack& stack);
int		PerformOperation(int a, int b, char c);

#endif
