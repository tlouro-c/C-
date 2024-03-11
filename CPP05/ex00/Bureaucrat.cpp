#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat ( void ) :  _grade( 150 ) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat ( std::string name, unsigned int grade ) : _name( name )
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat ( const Bureaucrat& other ) : _name( other._name )
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other )
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (_grade);
}

//* Nested Exception Classes

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low...");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high...");
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& Bureaucrat )
{
	os << Bureaucrat.getName() << " , bureaucrat grade " << Bureaucrat.getGrade() << std::endl;
	return (os);
}

void	Bureaucrat::incrementGrade( void )
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade( void )
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

