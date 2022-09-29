#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
	public:
		HumanA(std::string name, Weapon& weapon); // Default constructor
		~HumanA(void); // Destructor

		void	attack(void);

	private:
		std::string _name;
		Weapon &_weapon;

};

#endif
