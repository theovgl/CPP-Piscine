#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap ct("Bob");
	ClapTrap ct2(ct);
	ClapTrap* ct3;

	ct3 = new ClapTrap("Raymond");

	ct.attack("Edgar");

	ct.takeDamage(3);
	ct.beRepaired(1);

	ct.takeDamage(8);
	ct.attack("You"); // Should not work
	ct.beRepaired(1); // Should not work

	delete ct3;

	return (0);
}
