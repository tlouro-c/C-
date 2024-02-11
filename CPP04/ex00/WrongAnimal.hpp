#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal{
protected:
	std::string _type;
public:
	WrongAnimal ( void );
	~WrongAnimal ( void );
	WrongAnimal ( std::string type );
	std::string	getType ( void ) const { return _type; }
	void	makeSound ( void ) const ;
};

#endif
