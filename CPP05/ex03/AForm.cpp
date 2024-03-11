#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( void ) : _isSigned ( false ), _signGrade( 150 ), _execGrade( 150 ) {}

AForm::AForm( std::string name, unsigned int signGrade, unsigned int execGrade ) : _name( name ),
																				_isSigned( false ),
																				_signGrade( signGrade ),
																				_execGrade( execGrade )
{
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
	else if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
}

AForm::AForm( const AForm& other ) : _name( other._name ),
							_isSigned( other._isSigned ),
							_signGrade( other._signGrade ),
							_execGrade( other._execGrade ) {}

AForm& AForm::operator=( const AForm& other )
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

std::string 	AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

unsigned int	AForm::getSignGrade() const
{
	return (_signGrade);
}

unsigned int	AForm::getExecGrade() const
{
	return (_execGrade);
}

void	AForm::beSigned( const Bureaucrat& bureaucrat )
{
	if (_signGrade < bureaucrat.getGrade())
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream& operator<<( std::ostream& os, const AForm& AForm )
{
	
	os << "-\nAForm name: " << AForm.getName() << "\n";
	os << "AForm Signed? " << (AForm.getIsSigned() ? "Yes\n" : "No\n");
	os << "Sign Grade: " << AForm.getSignGrade() << "\n";
	os << "Execution Grade " << AForm.getExecGrade() << "\n-" << std::endl;
	return (os);
}

AForm::~AForm( void ) {}

//* Nested Exception Classes

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low...");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high...");
}

const char* AForm::FormNotSigned::what() const throw() 
{
	return ("Form needs to be signed first...");
}
