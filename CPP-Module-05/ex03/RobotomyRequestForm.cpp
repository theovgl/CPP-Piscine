#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
	Form("Robotomy", 72, 45),
	_target("Default target")
{
	std::cout << "Robotomy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target):
	Form("Robotomy", 72, 45),
	_target(target)
{
	std::cout << "Robotomy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->_signed && executor.getGrade() <= this->_gradeToExecute)
	{
		std::cout << "* drilling noise *" << std::endl;
		if (rand() % 1 + 2 == 1)
			std::cout << this->_target << " has been successfully robotomized!" << std::endl;
		else
		{
			std::cout << "Error: Robotomization has failed" << std::endl;
		}
	}
	else if (executor.getGrade() > this->_gradeToExecute)
		throw(Form::GradeTooLowException());
	else if (!this->_signed)
		throw(Form::FormNotSignedException());
}

Form* RobotomyRequestForm::builder(std::string const &target)
{
	return new RobotomyRequestForm(target);
}
