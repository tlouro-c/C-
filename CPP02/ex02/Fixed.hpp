#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{
private:
	int	num;
	static const int fract = 8;
public:
	Fixed( void );
	Fixed( const int );
	Fixed( const float );
	Fixed( const Fixed& other );
	~Fixed ( void );
	Fixed& operator=( const Fixed& other );
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
	static const Fixed& max( const Fixed& a, const Fixed& b);
	static const Fixed& min( const Fixed& a, const Fixed& b);
	static Fixed& max( Fixed& a, Fixed& b);
	static Fixed& min( Fixed& a, Fixed& b);

	// Comparision operators
	bool operator>(const Fixed& a);
	bool operator<(const Fixed& a);
	bool operator>=(const Fixed& a);
	bool operator<=(const Fixed& a);
	bool operator==(const Fixed& a);
	bool operator!=(const Fixed& a);

	// Arithmetic operators
	Fixed operator+( const Fixed& other );
	Fixed operator-( const Fixed& other );
	Fixed operator/( const Fixed& other );
	Fixed operator*( const Fixed& other );

	// Increment/Decrement operators
	Fixed operator++( int );
	Fixed& operator++( void );
	Fixed operator--( int );
	Fixed& operator--( void );
};

std::ostream& operator<<( std::ostream& out, const Fixed& fixed );

#endif
