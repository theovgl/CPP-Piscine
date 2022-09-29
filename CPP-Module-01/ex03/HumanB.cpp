#include "HumanB.hpp"
#include <iostream>
#include <string>

void HumanB::setWeapon(Weapon& weaponType)
{
	this->_weapon = &weaponType;
}

void HumanB::attack(void)
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon" << std::endl;
}

HumanB::HumanB(void)
{
	this->_name = "anonymous";
	this->_weapon = NULL;
}

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB(void)
{
}
