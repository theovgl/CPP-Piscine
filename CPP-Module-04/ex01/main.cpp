#include "Dog.hpp"
#include "Cat.hpp"
// #include "Animal.hpp"
#include "WrongCat.hpp"


//		FAKE CLASS FOR TEST

// class FakeCat
// {
// 	public:
// 		FakeCat(void){
// 			this->_brain = new Brain();
// 			std::cout << "A new FakeCat is born" << std::endl;
// 		}
// 		FakeCat(const FakeCat& src){
// 			this->_brain = src._brain;
// 		}
// 		~FakeCat(void){
// 			std::cout << "A FakeCat is dead" << std::endl;
// 		}
// 		FakeCat &operator=(const FakeCat&);
// 		void makeSound(void) const;
// 		void *getAddress(){return this->_brain;};

// 		Brain* _brain;
// };

int	main(void)
{
	{
		std::cout << "===== 100 animals =====" << std::endl;

		Animal* animals[100];

		for(int i = 0; i < 100; i++)
		{
			if (i < 50)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		for(int i = 0; i < 100; i++)
			delete animals[i];
		std::cout << std::endl;
	}

	// {
	// 	std::cout << "===== DEEP COPIES =====" << std::endl;

	// 	Cat real_cat;
	// 	Cat copy_cat(real_cat);
	// 	FakeCat fake_cat;
	// 	FakeCat copy_fake_cat(fake_cat);

	// 	std::cout << real_cat.getAddress() << std::endl;
	// 	std::cout << copy_cat.getAddress() << std::endl;

	// 	std::cout << fake_cat.getAddress() << std::endl;
	// 	std::cout << copy_fake_cat.getAddress() << std::endl;

	// 	delete fake_cat._brain;
	// }
	return 0;
}
