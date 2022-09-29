#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>
# include <iostream>

class WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal&);
		~WrongAnimal(void);
		WrongAnimal &operator=(const WrongAnimal&);

		std::string getType(void) const;
		void setType(std::string);
		void makeSound(void) const;

	protected:
		std::string _type;
};

#endif
