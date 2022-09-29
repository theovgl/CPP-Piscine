#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	public:
		Weapon(void); // Default constructor
		Weapon(std::string);
		~Weapon(void); // Destructor

		const std::string&	getType(void);
		void	setType(std::string newType);

	private:
		std::string	_type;
};

#endif
