#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form {
public:
	Form( std::string name, unsigned int signGrade, unsigned int execGrade );
	Form( Form& other );
	Form& operator=( Form& other );
	std::string 	getName() const;
	bool			getIsSigned() const;
	unsigned int	getSignGrade() const;
	unsigned int	getExecGrade() const;
	void	beSigned( const Bureaucrat& bureaucrat );
private:
	Form ( void );
	std::string const	_name;
	bool				_isSigned;
	unsigned int const	_signGrade;
	unsigned int const	_execGrade;

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const _NOEXCEPT;
	};

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const _NOEXCEPT;
	};
};

std::ostream& operator<<( std::ostream& os, const Form& Form );

#endif
