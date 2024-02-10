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
};

#endif
