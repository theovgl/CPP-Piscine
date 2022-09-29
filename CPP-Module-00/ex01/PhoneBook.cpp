#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
}

PhoneBook::~PhoneBook(void)
{
}

bool	PhoneBook::_check_input(std::string input)
{
	if (input == "")
	{
		std::cout << "Invalid input" << std::endl;
		return (false);
	}
	return (true);
}

bool PhoneBook::_set_contact_infos()
{
	std::string fName = "";
	std::string lName = "";
	std::string nName = "";
	std::string number = "";
	std::string secret = "";

	std::cout << "First name: ";
	std::getline(std::cin, fName);
	if (!_check_input(fName))
		return (false);
	std::cout << "Last name: ";
	std::getline(std::cin, lName);
	if (!_check_input(lName))
		return (false);
	std::cout << "Nickname: ";
	std::getline(std::cin, nName);
	if (!_check_input(nName))
		return (false);
	std::cout << "Phone number: ";
	std::getline(std::cin, number);
	if (!_check_input(number))
		return (false);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, secret);
	if (!_check_input(secret))
		return (false);
	this->contact[this->_index % 8].save_info(fName, lName, nName, number, secret);
	return (true);
}

void PhoneBook::add(void)
{
	if (_set_contact_infos() == false)
		return ;
	this->_index++;
}

void PhoneBook::_print_header(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void PhoneBook::_print_footer(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
}

void PhoneBook::_print_list(void)
{
	if (this->_index > 7)
	{
		for (int i = 0; i < 8; i++)
			this->contact[i].print_info_row(i);
	}
	else
	{
		for (int i = 0; i < this->_index; i++)
			this->contact[i].print_info_row(i);
	}
	if (this->_index)
		this->_print_footer();
}

void PhoneBook::search(void)
{
	int		to_search;
	std::string input;

	if (this->_index == 0)
		std::cout << "Your phonebook is empty" << std::endl;
	else
	{
		_print_header();
		_print_list();
		std::cout << "Type the index to search: ";
		if(!std::getline(std::cin, input))
			return ;
		to_search = std::atoi(input.c_str());
		if (input == "" || (to_search < 0 || to_search > 7)
			 || !std::isdigit(input[0]))
		{
			std::cin.clear();
			std::cout << "Invalid input" << std::endl;
		}
		else
		{
			this->contact[to_search].print_info_list();
		}
	}
}
