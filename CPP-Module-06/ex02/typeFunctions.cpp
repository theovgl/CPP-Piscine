#include "typeFunctions.hpp"

Base* generate(void)
{
	int random;

	srand(time(NULL));
	random = rand() % 3;
	if (random == 0)
	{
		return (new A());
	} else if (random == 1)
	{
		return (new B());
	} else
	{
		return (new C());
	}
}

void identify(Base* p)
{
	A *a;
	B *b;
	C *c;

	a = dynamic_cast<A*>(p);
	if (a != NULL)
		std::cout << "A" << std::endl;

	b = dynamic_cast<B*>(p);
	if (b != NULL)
		std::cout << "B" << std::endl;

	c = dynamic_cast<C*>(p);
	if (c != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}
