#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl
{
	private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
		std::string complainList[4];

	public:
		Harl(void); // Default constructor
		~Harl(void); // Destructor
		void complain(std::string level);
};

#endif
