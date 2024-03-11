#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( void ) : _isSigned ( false ), _signGrade( 150 ), _execGrade( 150 ) {}

Form::Form( std::string name, unsigned int signGrade, unsigned int execGrade ) : _name( name ),
																				_isSigned( false ),
																				_signGrade( signGrade ),
																				_execGrade( execGrade )
{
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
	else if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
}

Form::Form( Form& other ) : _name( other._name ),
							_isSigned( other._isSigned ),
							_signGrade( other._signGrade ),
							_execGrade( other._execGrade ) {}

Form& Form::operator=( Form& other )
{
	this->_isSigned = other._isSigned;
	return (*this);
}

std::string 	Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

unsigned int	Form::getSignGrade() const
{
	return (_signGrade);
}

unsigned int	Form::getExecGrade() const
{
	return (_execGrade);
}

void	Form::beSigned( const Bureaucrat& bureaucrat )
{
	if (_signGrade < bureaucrat.getGrade())
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream& operator<<( std::ostream& os, const Form& Form )
{
	
	os << "-\nForm name: " << Form.getName() << "\n";
	os << "Form Signed? " << (Form.getIsSigned() ? "Yes\n" : "No\n");
	os << "Sign Grade: " << Form.getSignGrade() << "\n";
	os << "Execution Grade " << Form.getExecGrade() << "\n-" << std::endl;
	return (os);
}

//* Nested Exception Classes

const char* Form::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Grade is too low...");
}

const char* Form::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Grade is too high...");
}
