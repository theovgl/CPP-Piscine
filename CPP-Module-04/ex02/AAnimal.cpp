#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
    this->_type = "";
    std::cout << "AAnimal is born" << std::endl;
}

AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal is dead" << std::endl;
}

AAnimal::AAnimal(const AAnimal&)
{

}

AAnimal& AAnimal::operator=(const AAnimal&)
{
	return *this;
}

void AAnimal::makeSound(void) const
{
	std::cout << "An AAnimal does not make sound" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (this->_type);
}

void	AAnimal::setType(std::string type)
{
	this->_type = type;
}