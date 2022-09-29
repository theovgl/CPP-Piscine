#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void); // Default constructor
		ScavTrap(std::string);
		ScavTrap(const ScavTrap&); // Copy constructor
		~ScavTrap(void); // Destructor
		ScavTrap &operator=(const ScavTrap&); // Affectation operator

		void guardGate();
		void attack(const std::string&);
};

#endif
