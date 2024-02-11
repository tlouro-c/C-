#include "Fixed.hpp"

//? https://spin.atomicobject.com/simple-fixed-point-math/

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

const Fixed& Fixed::max( const Fixed& a, const Fixed& b)
{
	if ( a.num > b.num)
		return  a;
	return b;
}

const Fixed& Fixed::min( const Fixed& a, const Fixed& b)
{
	if ( a.num < b.num)
		return  a;
	return b;
}

Fixed& Fixed::max( Fixed& a, Fixed& b)
{
	if ( a.num > b.num)
		return  a;
	return b;
}

Fixed& Fixed::min( Fixed& a, Fixed& b)
{
	if ( a.num < b.num)
		return  a;
	return b;
}

std::ostream& operator<<( std::ostream& out, const Fixed& fixed )
{
	out << fixed.toFloat();
	return out; 
}

bool Fixed::operator>(const Fixed& a)
{
	return (this->num > a.num);
}

bool Fixed::operator<(const Fixed& a)
{
	return (this->num < a.num);
}

bool Fixed::operator>=(const Fixed& a)
{
	return (this->num >= a.num);
}

bool Fixed::operator<=(const Fixed& a)
{
	return (this->num <= a.num);
}

bool Fixed::operator==(const Fixed& a)
{
	return (this->num == a.num);
}

bool Fixed::operator!=(const Fixed& a)
{
	return (this->num != a.num);
}

Fixed Fixed::operator+( const Fixed& other )
{
	Fixed	res;

	res.num = this->num + other.num;
	return res;
}

Fixed Fixed::operator-( const Fixed& other )
{
	Fixed	res;

	res.num = this->num - other.num;
	return res;
}

Fixed Fixed::operator/( const Fixed& other )
{
	Fixed	res;

	res.num = (this->num / other.num) * (1 << 16);
	return res;
}

Fixed Fixed::operator*( const Fixed& other )
{
	Fixed	res;

	res.num = (static_cast<int64_t>(this->num) * static_cast<int64_t>(other.num)) / (1 << fract);
	return res;
}

Fixed Fixed::operator++( int )
{
	Fixed res;

	res.num = this->num++;
	return res;
}

Fixed Fixed::operator--( int )
{
	Fixed res;

	res.num = this->num--;
	return res;
}

Fixed& Fixed::operator++( void )
{
	this->num++;
	return *this;
}

Fixed& Fixed::operator--( void )
{
	this->num--;
	return *this;
}
