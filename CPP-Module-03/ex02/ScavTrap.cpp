#include "ScavTrap.hpp"
#include <iostream>

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap switched to Gate keeper mode " << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		this->_energyPoints--;

		std::cout << "ScavTrap "
			<< this->_name
			<< " attacks "
			<< target
			<< ", causing "
			<< this->_attackDamage <<
			" points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " is dead or to tired to attack..." << std::endl;	
}

ScavTrap::ScavTrap(void)
{
	this->_name = "Anonymous";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " created" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & src)
{
	this->_name = src._name;
	std::cout << "ScavTrap " << this->_name << " copied" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " deleted" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap&)
{
	return *this;
}

