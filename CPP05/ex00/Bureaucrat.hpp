#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat {
public:
	Bureaucrat ( std::string name, unsigned int grade );
	Bureaucrat ( const Bureaucrat& other );
	Bureaucrat& operator=( const Bureaucrat& other );
	std::string getName() const;
	unsigned int getGrade() const;
	void	incrementGrade( void );
	void	decrementGrade( void );
private:
	Bureaucrat ( void );
	std::string const	_name;
	unsigned int		_grade;

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& Bureaucrat );

#endif
