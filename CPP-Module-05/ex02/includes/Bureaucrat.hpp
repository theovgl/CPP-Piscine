#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include <stdexcept>

class Form;
# include <Form.hpp>

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const, int);
		Bureaucrat(const Bureaucrat&);
		~Bureaucrat(void);
		Bureaucrat &operator=(const Bureaucrat&);

		std::string getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(int);
		void		decrementGrade(int);
		void		signForm(Form &);
		void		executeForm(Form const & form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: grade is too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: grade is too low");
				}
		};

	private:
		std::string const _name;
		int			_grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
