#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
		WrongCat(void);
		~WrongCat(void);
		WrongCat &operator=(const WrongCat&);
		void makeSound(void) const;
};

#endif
