#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	{
		std::cout << "===== Form tests =====" << std::endl;
		std::cout << std::endl << "== ShrubberyCreationFormPardonForm ==" << std::endl;
		Bureaucrat test("The goat", 10);
		ShrubberyCreationForm formTest;

		std::cout << formTest << std::endl;
		test.executeForm(formTest);
		test.signForm(formTest);
		test.executeForm(formTest);
	}
	{
		std::cout << std::endl << "== RobotomyRequestForm ==" << std::endl;
		Bureaucrat test("The goat", 10);
		RobotomyRequestForm formTest;

		std::cout << formTest << std::endl;

		try {
			test.executeForm(formTest);
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		try {	
			test.signForm(formTest);
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			test.executeForm(formTest);
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "== PresidentialPardonForm ==" << std::endl;
		Bureaucrat test("The goat", 5);
		PresidentialPardonForm formTest("Edward Snowden");

		std::cout << formTest << std::endl;
		try {	
			test.signForm(formTest);
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			test.executeForm(formTest);
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
