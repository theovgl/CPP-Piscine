#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{

		std::cout << "===== Bureaucrat tests =====" << std::endl;

		std::cout << "== Working ==" << std::endl;
		try
		{
			Bureaucrat henry("Henry", 15);
			Bureaucrat georges("Georges", 120);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "== Error ==" << std::endl;
		try
		{
			Bureaucrat alfred("Alfred", 170);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			Bureaucrat georgette("Georgette", 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "===== Form tests =====" << std::endl;
		Bureaucrat test("The goat", 10);
		Bureaucrat bad("The worst", 120);
		Form formTest("important", 15, 5);

		test.signForm(formTest);
		bad.signForm(formTest);
		std::cout << "== Error ==" << std::endl;
		try {
			Form badForm("tooHigh", 10, 0);
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			Form lowForm("tooLow", 160, 10);
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
