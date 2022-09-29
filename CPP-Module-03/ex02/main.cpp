#include "FragTrap.hpp"

#include <iostream>
#include <string>

int	main(void)
{
	std::cout << "** FRAGTRAP **" << std::endl;
	FragTrap ft("Charles");

	FragTrap ft2(ft);

	ft.attack("Bob");
	ft.highFivesGuys();
	ft.beRepaired(10);

	ft.takeDamage(200);
	ft.attack("Bob"); // Should not work
}
