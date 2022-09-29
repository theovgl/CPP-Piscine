#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		std::cout << "===== Form tests =====" << std::endl;
		Bureaucrat goat("the goat", 1);
		Intern arnaud;

		try
		{
			delete arnaud.makeForm("presidential pardon", "John Doe");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			delete arnaud.makeForm("robotomy request", "John Doe");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			Form* form= arnaud.makeForm("shrubbery creation", "John Doe");
			goat.signForm(*form);
			goat.executeForm(*form);
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			arnaud.makeForm("this form does not exists", "John Doe");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}
