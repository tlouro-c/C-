#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain {
public:
	Brain( void );
	~Brain ( void );
	Brain ( const Brain& other );
	Brain& operator=( const Brain& other);
	void setIdea( int index, std::string idea);
	std::string getIdea( int index );
private:
	std::string _ideas[100];
};

#endif
