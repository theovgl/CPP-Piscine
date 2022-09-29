#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
	Form("Presidential", 25, 5),
	_target("Default target")
{
	std::cout << "Presidential form constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target):
	Form("Presidential", 25, 5),
	_target(target)
{
	std::cout << "Presidential form constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Presidential form destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->_signed && executor.getGrade() <= this->_gradeToExecute)
	{
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	else if (executor.getGrade() > this->_gradeToExecute)
		throw(Form::GradeTooLowException());
	else if (!this->_signed)
		throw(Form::FormNotSignedException());
}

Form* PresidentialPardonForm::builder(std::string const &target)
{
	return new PresidentialPardonForm(target);
}
