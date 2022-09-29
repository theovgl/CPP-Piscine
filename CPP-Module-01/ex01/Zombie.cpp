#include "Zombie.hpp"
#include <iostream>

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

Zombie::Zombie(void)
{

}

Zombie::~Zombie(void)
{
	std::cout << this->_name << ": Zombie deleted" << std::endl;
}
