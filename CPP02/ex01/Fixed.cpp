#include "Fixed.hpp"

Fixed& Fixed::operator=( const Fixed& other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->num = other.num;
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (num);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	num = raw;
}

Fixed::Fixed( void ) : num(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed ( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed& other ) : num(other.num)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed( const int value ) : num( value << fract )
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float value ) : num(static_cast<int>(round(value * (1 << fract))))
{
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
	return static_cast<float>(num) / (1 << fract);
}

int Fixed::toInt( void ) const
{
	return (num >> fract);
}

std::ostream& operator<<( std::ostream& out, const Fixed& fixed )
{
	out << fixed.toFloat();
	return out; 
}

