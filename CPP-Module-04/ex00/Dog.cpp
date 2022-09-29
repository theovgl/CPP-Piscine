#include "Dog.hpp"

Dog::Dog(void)
{
	setType("Dog");
	std::cout << "A new Dog is born" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "A dog is dead" << std::endl;
}

Dog::Dog(const Dog&)
{

}

Dog& Dog::operator=(const Dog&)
{
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Wooooof Wooooof" << std::endl;
}

