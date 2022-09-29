#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name(""), _grade(150)
{
	std::cout << "Default constructor called";
}

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name), _grade(grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "The Bureaucrat " << this->_name << " is born with grade " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat&)
{

}


Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << this->_name << " has been killed" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	this->_grade = rhs._grade;
	std::cout << "Assignement operator called" << std::endl;
	return *this;
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade(int value)
{
	if ((this->_grade - value) < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= value;
}

void Bureaucrat::decrementGrade(int value)
{
	if ((this->_grade + value) > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += value;
}

void Bureaucrat::signForm(Form &toSign)
{
	try
	{
		toSign.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
		std::cerr << this->getName() << " couldn't sign "
		<< toSign.getName() << " because "
		<< e.what()
		<< std::endl;
	}
}

void Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}
