#include "Zombie.h"

Zombie* newZombie(std::string name)
{
	Zombie* to_return = new Zombie(name);
	return (to_return);
}
