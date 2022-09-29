#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <string>
# include <iostream>

class AAnimal {
	public:
		AAnimal(void);
		AAnimal(const AAnimal&);
		virtual ~AAnimal(void);
		AAnimal &operator=(const AAnimal&);

		std::string getType(void) const;
		void setType(std::string);
		virtual void makeSound(void) const = 0;

	protected:
		std::string _type;
};

#endif
