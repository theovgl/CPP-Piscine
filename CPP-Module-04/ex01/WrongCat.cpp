#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	setType("WrongCat");
	std::cout << "A new WrongCat is born" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "A WrongCat is dead" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat&)
{
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Miaouwwww Miaouwwww" << std::endl;
}
