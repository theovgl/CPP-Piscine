#include "Zombie.hpp"
#include "Zombie.h"

int main(void)
{
	Zombie* Theo = newZombie("Théo");

	Theo->announce();
	randomChump("Poupoup");

	delete Theo;
	return (0);
}
