#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const target);
		~PresidentialPardonForm();

	private:
		std::string	const _target;
		void execute(Bureaucrat const &) const;
};

#endif
