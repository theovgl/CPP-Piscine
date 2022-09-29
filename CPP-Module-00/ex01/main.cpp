#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

static void	print_welcome(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|         Welcome to your phonebook         |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|  Commands:                                |" << std::endl;
	std::cout << "|   - ADD: Add a contact to your phonebook  |" << std::endl;
	std::cout << "|   - SEARCH: List your contacts            |" << std::endl;
	std::cout << "|   - EXIT: Leave the program               |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
}

static void	print_help(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|  Commands:                                |" << std::endl;
	std::cout << "|   - ADD: Add a contact to your phonebook  |" << std::endl;
	std::cout << "|   - SEARCH: List your contacts            |" << std::endl;
	std::cout << "|   - EXIT: Leave the program               |" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
}

int	main(void)
{
	PhoneBook annuaire;
	std::string input;

	print_welcome();
	while (std::getline(std::cin, input))
	{
		if (input == "ADD")
			annuaire.add();
		else if (input == "SEARCH")
			annuaire.search();
		else if (input == "EXIT")
			break ;
		else if (input != "")
		{
			std::cin.clear();
			print_help();
		}
	}
	return (0);
}
