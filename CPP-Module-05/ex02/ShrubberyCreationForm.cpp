#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	Form("Shrubbery", 145, 137),
	_target("Default target")
{
	std::cout << "Shrubbery constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) :
	Form("Shrubbery", 145, 137),
	_target(target)
{
	std::cout << "Shrubbery constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Shrubbery destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->_signed && executor.getGrade() <= this->_gradeToExecute)
	{
		std::string filename = this->_target;
		filename.append( "_shrubbery");
		std::ofstream ofs;
		ofs.open(filename.c_str());
		ofs << "       _-_" << std::endl;
		ofs << "    /~~   ~~\\" << std::endl;
		ofs << " /~~         ~~\\" << std::endl;
		ofs << "{               }" << std::endl;
		ofs << " \\  _-     -_  /" << std::endl;
		ofs << "   ~  \\\\ //  ~" << std::endl;
		ofs << "_- -   | | _- _" << std::endl;
		ofs << "  _ -  | |   -_" << std::endl;
		ofs << "      // \\\\" << std::endl;
		ofs.close();
	}
	else if (executor.getGrade() > this->_gradeToExecute)
		throw(Form::GradeTooLowException());
	else if (!this->_signed)
		throw(Form::FormNotSignedException());
}
