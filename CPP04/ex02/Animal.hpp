#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal{
protected:
	std::string _type;
public:
	Animal ( void );
	Animal ( const Animal& other );
	virtual ~Animal ( void );
	Animal ( std::string type );
	std::string	getType ( void ) const { return _type; }
	virtual void	makeSound ( void ) const  = 0;

	Animal& operator=( const Animal& other );
};

#endif
