#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie{
public:
	void	announce( void );
	void	SetName( std::string name );
	Zombie 	( std::string name ):name(name){};
	Zombie ( void ){};
	~Zombie ( void );
private:
	std::string name;
};

#endif
