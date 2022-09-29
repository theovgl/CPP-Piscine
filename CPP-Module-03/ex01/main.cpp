#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap st("Bob");
	ScavTrap* st2;

	st2 = new ScavTrap("Georges");
	
	ScavTrap st3(*st2);

	st.attack("Edgar");
	
	st.takeDamage(3);
	st.beRepaired(1);

	st.takeDamage(100);
	st.attack("Georges");
	st.guardGate();

	st.beRepaired(1); // Should not work
	
	delete st2;

	return (0);
}