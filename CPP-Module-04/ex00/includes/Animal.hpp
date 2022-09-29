#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

class Animal {
	public:
		Animal(void);
		Animal(const Animal&);
		virtual ~Animal(void);
		Animal &operator=(const Animal&);

		std::string getType(void) const;
		void setType(std::string);
		virtual void makeSound(void) const;

	protected:
		std::string _type;
};

#endif
