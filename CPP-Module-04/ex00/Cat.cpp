#include "Cat.hpp"

Cat::Cat(void)
{
	setType("Cat");
	std::cout << "A new Cat is born" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "A Cat is dead" << std::endl;
}

Cat::Cat(const Cat&)
{

}

Cat& Cat::operator=(const Cat&)
{
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Miaouwwww Miaouwwww" << std::endl;
}
