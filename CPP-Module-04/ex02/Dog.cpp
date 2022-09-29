#include "Dog.hpp"

Dog::Dog(void)
{
	setType("Dog");
	this->_brain = new Brain();
	std::cout << "A new Dog is born" << std::endl;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "A dog is dead" << std::endl;
}

Dog::Dog(const Dog& src)
{
	this->_brain = src._brain;
}

Dog& Dog::operator=(const Dog&)
{
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Wooooof Wooooof" << std::endl;
}

