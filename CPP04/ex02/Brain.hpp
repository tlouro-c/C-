#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain{
private:
	std::string _ideas[100];
public:
	Brain ( void );
	Brain ( const Brain& other );
	~Brain ( void );
	Brain& operator=( const Brain& other);
};

#endif
