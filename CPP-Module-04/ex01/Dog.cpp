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
	this->_brain = new Brain(*src._brain);
	std::cout << "Copy constructor from Dog called" << std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
	delete this->_brain;
	this->_brain = new Brain(*src._brain);
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Wooooof Wooooof" << std::endl;
}

