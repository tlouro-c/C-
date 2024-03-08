#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

typedef unsigned int uint;

class ClapTrap{
protected:
	std::string _name;
	uint		_hitPoints;
	uint		_energyPoints;
	uint		_attackDamage;
public:
	ClapTrap( void );
	ClapTrap( const ClapTrap&  other );
	ClapTrap( const std::string& name );
	~ClapTrap( void );
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	uint getAD( void );

	ClapTrap& operator=( const ClapTrap& other);
};

#endif
