#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class AForm {
public:
	AForm( std::string name, unsigned int signGrade, unsigned int execGrade );
	AForm( const AForm& other );
	virtual ~AForm( void ) {};
	AForm& operator=( const AForm& other );
	std::string 	getName() const;
	bool			getIsSigned() const;
	unsigned int	getSignGrade() const;
	unsigned int	getExecGrade() const;
	void	beSigned( const Bureaucrat& bureaucrat );
	virtual void execute(Bureaucrat const & executor) const = 0;
private:
	std::string const	_name;
	bool				_isSigned;
	unsigned int const	_signGrade;
	unsigned int const	_execGrade;
protected:
	AForm ( void );
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const _NOEXCEPT;
	};

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const _NOEXCEPT;
	};

	class FormNotSigned : public std::exception {
	public:
		const char* what() const _NOEXCEPT;
	};
};

std::ostream& operator<<( std::ostream& os, const AForm& Form );

#endif
