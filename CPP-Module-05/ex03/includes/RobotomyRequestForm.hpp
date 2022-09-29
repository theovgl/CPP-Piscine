#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <string>
# include <cstdlib>

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const target);
		~RobotomyRequestForm(void);

		static Form* builder(std::string const &target);

	private:
		std::string	const _target;
		void execute(Bureaucrat const &) const;
};

#endif
