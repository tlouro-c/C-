#include "ScalarConverter.hpp"

static void	fromInt(std::string stringLiteral)
{
	try 
	{
		int representation = std::atoi(stringLiteral.c_str());
		std::cout << "char: " ;
		if (std::isprint(representation))
			std::cout << "'" << static_cast<char>(representation) << "'\n";
		else
			std::cout << "non-displayable\n";
		std::cout << "int: " << representation << "\n";
		std::cout << "float: " << static_cast<float>(representation) << ".0f\n";
		std::cout << "double: " << static_cast<double>(representation) << ".0" << std::endl;
	}
	catch (std::exception&)
	{
		std::cout << "char: " << "impossible" << "\n";
		std::cout << "int: " << "impossible" << "\n";
		std::cout << "float: " << "nanf\n";
		std::cout << "double: " << "nan" << std::endl;
	}
}

static void	fromChar(std::string stringLiteral)
{
	char	representation = stringLiteral[0];

	std::cout << "char: " ;
	if (std::isprint(representation))
		std::cout << "'" << static_cast<char>(representation) << "'\n";
	else
		std::cout << "non-displayable\n";
	std::cout << "int: " << static_cast<int>(representation) << "\n";
	std::cout << "float: " << static_cast<float>(representation) << ".0f\n";
	std::cout << "double: " << static_cast<double>(representation) << ".0" << std::endl;
}

static void	fromFloat(std::string stringLiteral)
{
	try 
	{
		float representation = std::atof(stringLiteral.c_str());
		std::cout << "char: '" 
		<< (std::isprint(representation) ? static_cast<char>(representation) : '?') << "'\n";
		std::cout << "int: " << static_cast<int>(representation) << "\n";
		std::cout << "float: " << representation << "f\n";
		std::cout << "double: " << static_cast<double>(representation) << std::endl;
	}
	catch (std::exception&)
	{
		std::cout << "char: " << "impossible" << "\n";
		std::cout << "int: " << "impossible" << "\n";
		std::cout << "float: " << "nanf\n";
		std::cout << "double: " << "nan" << std::endl;
	}
}

static void	fromDouble(std::string stringLiteral)
{
	try 
	{
		double representation = std::atof(stringLiteral.c_str());
		std::cout << "char: '" 
		<< (std::isprint(representation) ? static_cast<char>(representation) : '?') << "'\n";
		std::cout << "int: " << static_cast<int>(representation) << "\n";
		std::cout << "float: " << static_cast<float>(representation) << "f\n";
		std::cout << "double: " << representation << std::endl;
	}
	catch (std::exception&)
	{
		std::cout << "char: " << "impossible" << "\n";
		std::cout << "int: " << "impossible" << "\n";
		std::cout << "float: " << "nanf\n";
		std::cout << "double: " << "nan" << std::endl;
	}
}

static void	fromInfinite(std::string stringLiteral)
{
	char	signal = stringLiteral[0] == '-';

	std::cout << "char: non-displayable\n";
	std::cout << "int: " << (signal ? "-inf" : "+inf") << "\n";
	std::cout << "float: " << (signal ? "-inff" : "+inff") << "\n";
	std::cout << "double: " << (signal ? "-inf" : "+inf")<< std::endl;
}


void	ScalarConverter::convert(std::string stringLiteral)
{
	if (stringLiteral.find_first_of('.', 0) != stringLiteral.npos
		&& stringLiteral.find_first_of('f', 0) != stringLiteral.npos)
		fromFloat(stringLiteral);
	else if (stringLiteral.find_first_of('.', 0) != stringLiteral.npos)
		fromDouble(stringLiteral);
	else if (stringLiteral.length() == 1 && !std::isdigit(stringLiteral[0]))
		fromChar(stringLiteral);
	else if (stringLiteral == "-inff" || stringLiteral == "-inf"
		|| stringLiteral == "+inff" || stringLiteral == "+inf")
		fromInfinite(stringLiteral);
	else
		fromInt(stringLiteral);
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	if (this != &other)
		*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

