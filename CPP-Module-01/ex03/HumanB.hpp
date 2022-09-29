#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
	public:
		HumanB(void);
		HumanB(std::string name);
		~HumanB(void); // Destructor

		void	setWeapon(Weapon& weaponType);
		void	attack(void);

	private:
		std::string _name;
		Weapon *_weapon;
};

#endif
