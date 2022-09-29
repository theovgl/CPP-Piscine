#include "Zombie.hpp"
#include "Zombie.h"

int main(int ac, char **av)
{
	int N = 5;

	if (ac != 2)
	{
		std::cout << "Wrong number of argument" << std::endl;
		return (1);
	}
	Zombie* zombies_array = zombieHorde(N, av[1]);
	for (int i = 0; i < N; i++) {
		zombies_array[i].announce();
	}

	delete[] zombies_array;
	return (0);
}
