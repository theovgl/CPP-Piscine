#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <string>
#include <fstream>

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const target);
		~ShrubberyCreationForm(void);


	private:
		std::string	const _target;
		void execute(Bureaucrat const &) const;
};

#endif
