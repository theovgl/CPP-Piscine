#include "FragTrap.hpp"
#include <iostream>

void FragTrap::attack(const std::string &target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		this->_energyPoints--;

		std::cout << "FragTrap "
			<< this->_name
			<< " attacks "
			<< target
			<< ", causing "
			<< this->_attackDamage <<
			" points of damage!" << std::endl;
	}
	else
		std::cout << "FragTrap " << this->_name << " is dead or to tired to attack..." << std::endl;	
}

void FragTrap::highFivesGuys(void)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "FragTrap " << this->_name << " is asking for a high fives !" << std::endl;
	}
}

FragTrap::FragTrap(void)
{
	this->_name = "Anonymous";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " created" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap & src)
{
	this->_name = src._name;
	std::cout << "FragTrap " << this->_name << " copied" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " deleted" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap&)
{
	return *this;
}
