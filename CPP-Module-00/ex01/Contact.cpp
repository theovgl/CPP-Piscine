#include "Contact.hpp"
#include <iomanip>

Contact::Contact(void)
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
}

Contact::~Contact(void)
{

}

void	Contact::save_info(std::string fName, std::string lName, std:: string nName, std::string nb, std::string secret)
{
	this->first_name = fName;
	this->last_name = lName;
	this->nickname = nName;
	this->phone_number = nb;
	this->darkest_secret = secret;
}

void	Contact::_format_string(std::string str)
{
	int	size;

	size = str.length();
	if (size > 10)
	{
		std::cout << str.substr(0, 9);
		std::cout << ".";
	}
	else
		std::cout << std::setw(10) << str;
	std::cout << "|";
}

void	Contact::print_info_row(int index)
{
	std::cout << "|";
	std::cout << std::setw(10) << index << "|";
	_format_string(this->first_name);
	_format_string(this->last_name);
	_format_string(this->nickname);
	std::cout << std::endl;
}

void	Contact::print_info_list(void)
{
	std::cout << "First Name: " << this->first_name << std::endl;
	std::cout << "Last Name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
}
