#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon{
public:
	const std::string& getType( void )const;
	void 			   setType( std::string newType );
	Weapon( std::string type ):_type(type){};
	Weapon ( void ){};
	Weapon& operator= ( const Weapon& newWeapon );
private:
	std::string _type;
};

#endif
