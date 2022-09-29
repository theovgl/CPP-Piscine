#include "Bureaucrat.hpp"

int main(void)
{
	/* SHOULD THROW AN ERROR */
	try
	{
		Bureaucrat bureaucrat("Liar", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	/* SHOULD THROW AN ERROR */
	try
	{
		Bureaucrat bureaucrat("bad_boy75", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	{
		/* SHOULD WORK FINE */
		try
		{
			Bureaucrat goat("GOAT", 1);
			goat.decrementGrade(10);
			std::cout << goat << std::endl;
			goat.incrementGrade(1);
			std::cout << goat << std::endl;
			goat.incrementGrade(10);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		/* SHOULD WORK FINE */
		try
		{
			Bureaucrat average("Average", 150);
			std::cout << average << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "==== Copy tests ====" << std::endl;
		Bureaucrat goat("GOAT", 1);
		Bureaucrat goat2(goat);

		std::cout << goat2 << std::endl;
	}
	return 0;
}
