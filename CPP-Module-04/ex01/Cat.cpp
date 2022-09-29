#include "Cat.hpp"

Cat::Cat(void)
{
	setType("Cat");
	this->_brain = new Brain();
	std::cout << "A new Cat is born" << std::endl;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "A Cat is dead" << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
	delete this->_brain;
	this->_brain = new Brain(*src._brain);
	return *this;
}

Cat::Cat(const Cat& src)
{
	this->_brain = new Brain(*src._brain);
	std::cout << "Copy constructor from Cat called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Miaouwwww Miaouwwww" << std::endl;
}

void* Cat::getAddress(void)
{
	return this->_brain;
}
