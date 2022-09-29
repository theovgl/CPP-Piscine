#ifndef INTERN_HPP
# define INTERN_HPP

#include <stdexcept>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern&);
		Intern &operator=(const Intern&);
		~Intern();
		Form*	makeForm(std::string formName, std::string target);

	private:
		std::string _formList[3];

	class BadFormName : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return("Error: this form does not exist");
			}
	};
};

#endif
