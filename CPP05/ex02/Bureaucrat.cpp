#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat ( void ) :  _grade( 150 ) {}

Bureaucrat::~Bureaucrat ( void ) {}

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

void	Bureaucrat::signAForm( AForm& AForm )
{
	if (AForm.getSignGrade() < _grade){
		std::cout << _name << " couldn't sign " << AForm.getName() << " because grade is too low..."<< std::endl; return;}
	else
		std::cout << _name << " signed " << AForm.getName() << std::endl;
	AForm.beSigned(*this);
}

void	Bureaucrat::executeForm(AForm const & form)
{
	if (!form.getIsSigned()){
		std::cout << "The form must be signed before execution..." << std::endl; return; }
	else if (_grade >= form.getExecGrade()){
		std::cout << "Grade too low..." << std::endl; return; }
	else
		std::cout << _name << " executed " << form.getName() << std::endl;
	form.execute(*this);
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
