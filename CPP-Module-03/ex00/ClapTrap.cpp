#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void): _name("Anonymous"),
		_hitPoints(10),
		_energyPoints(10),
		_attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " created" << std::endl;
}

ClapTrap::ClapTrap(std:: string const name): _name(name),
		_hitPoints(10),
		_energyPoints(10),
		_attackDamage(0)
{
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src): _name(src._name)
{
	std::cout << "ClapTrap " << this->_name << " copied" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " deleted" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap&)
{
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		this->_energyPoints--;

		std::cout << "ClapTrap "
			<< this->_name
			<< " attacks "
			<< target
			<< ", causing "
			<< this->_attackDamage <<
			" points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " cannot attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;

	std::cout << "ClapTrap "
		<< this->_name
		<< " lost "
		<< amount
		<< " health points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		this->_hitPoints += amount;
		this->_energyPoints--;

		std::cout << "ClapTrap "
		<< this->_name
		<< " gain "
		<< amount
		<< " health points!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " cannot be repaired" << std::endl;
}
