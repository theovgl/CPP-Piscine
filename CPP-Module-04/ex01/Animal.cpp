#include "Animal.hpp"

Animal::Animal(void)
{
	this->_type = "";
	std::cout << "A new Animal is born" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal is dead" << std::endl;
}

Animal::Animal(const Animal&)
{
}

Animal& Animal::operator=(const Animal&)
{
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << "An animal does not make sound" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::setType(std::string type)
{
	this->_type = type;
}
