#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target )
					: AForm("PresidentialPardonForm", 72, 45), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) : AForm( other )
																			, _target( other._target ) {}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other )
{
	(void)other;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	std::srand(std::time(NULL));
	if (!this->getIsSigned())
		throw FormNotSigned();
	else if (executor.getGrade() >= this->getExecGrade())
		throw GradeTooLowException();
	std::cout << _target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}

