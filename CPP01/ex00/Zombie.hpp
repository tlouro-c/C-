#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie{
public:
	void	announce( void );
	Zombie 	( std::string name ):name(name){};
	~Zombie ( void );
private:
	std::string name;
	Zombie ( void );
};

#endif
