#include "Weapon.hpp"
#include <iostream>
#include <string>

const std::string& Weapon::getType(void)
{
	return (this->_type);
}

void Weapon::setType(std::string newType)
{
	this->_type = newType;
}

Weapon::Weapon(): _type("weapon")
{
}

Weapon::Weapon(std::string name): _type(name)
{
}

Weapon::~Weapon(void)
{
}
