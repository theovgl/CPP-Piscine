#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string);
		FragTrap(const FragTrap&);
		~FragTrap(void);
		FragTrap &operator=(const FragTrap&);

		void highFivesGuys(void);
		void attack(const std::string&);
};

#endif
