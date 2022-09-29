#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->_type = "";
	std::cout << "A new WrongAnimal is born" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "An WrongAnimal is dead" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal&)
{
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal&)
{
	return *this;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "An WrongAnimal does not make sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::setType(std::string type)
{
	this->_type = type;
}
