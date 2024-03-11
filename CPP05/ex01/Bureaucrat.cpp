#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat ( void ) :  _grade( 150 ) {}

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

void	Bureaucrat::signForm( Form& form )
{
	if (form.getSignGrade() < _grade)
		std::cout << _name << " couldn't sign " << form.getName() << " because grade is too low..."<< std::endl;
	else
		std::cout << _name << " signed " << form.getName() << std::endl;
	form.beSigned(*this);
}

//* Nested Exception Classes

const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Grade is too low...");
}

const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Grade is too high...");
}
