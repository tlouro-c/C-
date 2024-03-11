#include "Intern.hpp"

AForm* Intern::makeForm( std::string formName, std::string target)
{
	AForm *PossibleForms[4] = {nullptr,
							new ShrubberyCreationForm(target),
							new PresidentialPardonForm(target),
							new RobotomyRequestForm(target)};
	int	formNamesIndex = ((formName == "ShrubberyCreationForm") * 1)
						+ ((formName == "PresidentialPardonForm") * 2)
						+ ((formName == "RobotomyRequestForm") * 3);
	AForm *finalSelection = PossibleForms[formNamesIndex];
	for (int i = 1; i < 4; i++)
	{
		if (PossibleForms[i] != finalSelection)
			delete (PossibleForms[i]);
	}
	return (finalSelection);
}
