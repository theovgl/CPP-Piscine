#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {
	public:
		Cat(void);
		Cat(const Cat&);
		virtual ~Cat(void);
		Cat &operator=(const Cat&);
		virtual void makeSound(void) const;

		void *getAddress();

	private:
		Brain* _brain;
};

#endif
