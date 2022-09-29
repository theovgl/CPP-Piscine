#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
	this->_formList[0] = "presidential pardon";
	this->_formList[1] = "robotomy request";
	this->_formList[2] = "shrubbery creation";
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

Form* Intern::makeForm(std::string formName, std::string target)
{
	std::cout << "Intern creates " << formName << std::endl;

	typedef Form* (*builder)(std::string const &target);

	builder formPointer[3] = {
		&PresidentialPardonForm::builder,
		&RobotomyRequestForm::builder,
		&ShrubberyCreationForm::builder
	};

	for (int i = 0; i < 3; i++)
	{
		if (this->_formList[i] == formName)
		{
			return formPointer[i](target);
		}
	}
	throw (Intern::BadFormName());
}
