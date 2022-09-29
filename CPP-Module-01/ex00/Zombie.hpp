#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie(void); // Default constructor
		Zombie(std::string);
		~Zombie(void); // Destructor

		void announce(void);

	private:
		std::string _name;
};

#endif
