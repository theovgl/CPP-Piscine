#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{
		std::cout << "== REGULAR ANIMALS ==\n" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << std::endl;
		std::cout << i->getType() << std::endl;
		i->makeSound(); //will output miaouw
		j->makeSound(); //will output woof
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	{
		std::cout << "\n== WRONG ANIMALS ==\n" << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();

		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
	}

	return 0;
}
