#include "RPN.hpp"

int	main(int argc, char* argv[])
{
	std::string	expression;
	if (argc != 2)
		return (std::cerr << "Invalid number of arguments" << std::endl, 1);

	expression = static_cast<std::string>(argv[1]);
	if (expression.find_first_not_of("0123456789+-/* ") != expression.npos)
		return (std::cerr << "Error..." << std::endl, 2);
	__intStack	exprStack;
	try {
		ReversePolishNotationCalculator(exprStack, expression); }
	catch (...) {
		return (std::cerr << "Error..." << std::endl, 3); }
	return (0);
}
