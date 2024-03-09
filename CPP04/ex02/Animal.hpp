#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal {
public:
	Animal( void );
	Animal( const Animal& other );
	virtual ~Animal( void );
	Animal& operator=( const Animal& other);
	virtual void makeSound( void ) const = 0;
	std::string getType( void ) const;
protected:
	std::string _type;
	Animal( std::string type );
};

#endif
