#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		void	save_info(std::string, std::string, std::string, std::string, std::string);
		void	print_info_row(int);
		void	print_info_list(void);

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
		void	_format_string(std::string);
};

#endif
