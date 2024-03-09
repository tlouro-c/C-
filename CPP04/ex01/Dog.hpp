#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
public:
	Dog( void );
	~Dog( void );
	Dog( const Dog& other );
	void makeSound( void ) const;
	void setIdea( int index, std::string idea);
	std::string getIdea( int index ) const;
	Dog& operator=( const Dog& other);
private:
	Brain*  _brain;
};

#endif
