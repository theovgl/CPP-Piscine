#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat;
# include <Bureaucrat.hpp>

class Form
{
	public:
		Form(void);
		Form(std::string const, const int, const int);
		Form &operator=(const Form&);
		Form(const Form&);
		virtual ~Form();

		std::string		getName() const;
		int				getGradeToSign();
		int				getGradeToExecute();
		bool			isSigned();
		void			beSigned(Bureaucrat&);
		virtual void	execute(Bureaucrat const &) const = 0;

	protected:
		std::string const 	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("grade is too high");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("grade is too low");
			}
	};

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error: form not signed");
			}
	};

};

std::ostream & operator<<(std::ostream &o, Form &rhs);

#endif
