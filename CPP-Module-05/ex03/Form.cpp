#include "Form.hpp"

Form::Form(void):
	_name(""),
	_gradeToSign(75),
	_gradeToExecute(10)
{
	std::cout << "Form default constructor called" << std::endl;
	this->_signed = false;
}

Form::Form(const Form& rhs):
	_name(rhs._name),
	_signed(rhs._signed),
	_gradeToSign(rhs._gradeToSign),
	_gradeToExecute(rhs._gradeToExecute)
{
	std::cout << "Form copied" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

Form & Form::operator=(Form const &rhs)
{
	(void)rhs;
	return *this;
}

Form::Form(std::string name, const int gradeToSign, const int gradeToExecute):
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	this->_signed = false;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form " << name << " created" << std::endl;
}

void Form::beSigned(Bureaucrat &worker)
{
	if (worker.getGrade() <= this->getGradeToSign())
	{
		this->_signed = true;
	} else
	{
		throw Form::GradeTooLowException();
	}
}

int Form::getGradeToExecute()
{
	return this->_gradeToExecute;
}

int Form::getGradeToSign()
{
	return this->_gradeToSign;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::isSigned()
{
	return this->_signed;
}

void Form::execute(Bureaucrat const &executor) const
{
	if (this->_signed && executor.getGrade() < this->_gradeToExecute)
	{
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	}
	else if (executor.getGrade() > this->_gradeToExecute)
		throw(Form::GradeTooLowException());
	else if (!this->_signed)
		throw(Form::FormNotSignedException());
}

std::ostream & operator<<(std::ostream &o, Form &rhs)
{
	o << "Form: " << rhs.getName()
		<< "Grade to sign: " << rhs.getGradeToSign()
		<< "Grade to execute: " << rhs.getGradeToExecute()
		<< ", is signed? " << rhs.isSigned();
	return o;
}
