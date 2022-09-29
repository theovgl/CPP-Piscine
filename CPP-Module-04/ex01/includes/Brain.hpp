#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain {

public:
	Brain(void);
	Brain(const Brain&);
	~Brain(void);
	Brain &operator=(const Brain&);

	std::string ideas[100];
};

#endif
