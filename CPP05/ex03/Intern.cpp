#include "Intern.hpp"

AForm* Intern::makeForm( std::string formName, std::string target)
{
	AForm *PossibleForms[4] = {NULL,
							new ShrubberyCreationForm(target),
							new PresidentialPardonForm(target),
							new RobotomyRequestForm(target)};
	int	formNamesIndex = ((formName == "ShrubberyCreationForm") * 1)
						+ ((formName == "PresidentialPardonForm") * 2)
						+ ((formName == "RobotomyRequestForm") * 3);
	AForm *finalSelection = PossibleForms[formNamesIndex];
	if (!finalSelection)
		std::cerr << "Not a valid form name!" << std::endl;
	for (int i = 1; i < 4; i++)
	{
		if (PossibleForms[i] != finalSelection)
			delete (PossibleForms[i]);
	}
	return (finalSelection);
}

Intern::Intern() {}

Intern::Intern(const Intern& other) {(void)other;}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() {}

