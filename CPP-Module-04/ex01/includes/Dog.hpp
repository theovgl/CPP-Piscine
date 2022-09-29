#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal {
	public:
		Dog(void);
		virtual ~Dog(void);
		Dog(const Dog&);
		Dog &operator=(const Dog&);
		virtual void makeSound(void) const;
	
	private:
		Brain* _brain;
};

#endif
