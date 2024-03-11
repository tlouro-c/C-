#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string target )
					: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) : AForm( other )
																			, _target( other._target ) {}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& other )
{
	(void)other;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	std::srand(std::time(NULL));
	if (!this->getIsSigned())
		throw FormNotSigned();
	else if (executor.getGrade() >= this->getExecGrade())
		throw GradeTooLowException();
	std::cout << "Makes some drilling noises.\n";
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomy Failure..." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm() {};

RobotomyRequestForm::~RobotomyRequestForm( void ) {};
