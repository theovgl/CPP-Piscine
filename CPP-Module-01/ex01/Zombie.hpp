#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie
{
	public:
		Zombie(void); // Default constructor
		~Zombie(void); // Destructor

		void announce(void);
		void setName(std::string);

	private:
		std::string	_name;
};

#endif
