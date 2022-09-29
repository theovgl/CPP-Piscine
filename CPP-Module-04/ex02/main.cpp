#include "Animal.hpp"
#include "AAnimal.hpp"
#include "Dog.hpp"

int main(void)
{
	// AAnimal impossible; // <- Should not work
	// Animal possible; // <- Should work
	AAnimal *test = new Dog();

	test->makeSound();
	delete test;
	// possible.makeSound();
}
