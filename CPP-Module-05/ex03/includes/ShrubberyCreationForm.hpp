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

		static Form* builder(std::string const &target);

	private:
		std::string	const _target;
		void execute(Bureaucrat const &) const;
};

#endif
