#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add(void);
		void	search(void);

	private:
		int	_index;
		Contact	contact[8];
		void	_print_header(void);
		void	_print_footer(void);
		void	_print_list(void);
		bool	_check_input(std::string);
		bool	_set_contact_infos(void);
};

#endif
