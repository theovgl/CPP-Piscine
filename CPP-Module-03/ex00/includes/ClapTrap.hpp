#ifndef CLAPTRAP_HPP 
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;

	public:
		ClapTrap(void); // Default constructor
		ClapTrap(std:: string const);
		ClapTrap(const ClapTrap&); // Copy constructor
		~ClapTrap(void); // Destructor
		ClapTrap &operator=(const ClapTrap&); // Affectation operator

		void attack(const std::string&);
		void takeDamage(unsigned int);
		void beRepaired(unsigned int);
};

#endif
