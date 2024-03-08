#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal {
public:
	WrongAnimal( void );
	WrongAnimal( const WrongAnimal& other );
	virtual ~WrongAnimal( void );
	WrongAnimal& operator=( const WrongAnimal& other);
	void makeSound( void ) const;
	std::string getType( void ) const;
protected:
	std::string _type;
	WrongAnimal( std::string type );
};

#endif
