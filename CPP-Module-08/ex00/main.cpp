#include "easyfind.hpp"
#include <vector>

int main()
{
	{
		std::vector<int> intVector;

		intVector.push_back(2);
		intVector.push_back(85);
		intVector.push_back(152);
		intVector.push_back(4);
		intVector.push_back(1024);
		intVector.push_back(2048);

		try
		{
			std::vector<int>::iterator ret;

			ret = easyfind(intVector, 1024);
			std::cout << "Find occurence: " << *ret << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "No occurence found" << std::endl;
		}
	}

	{
		std::vector<char> charVector;

		charVector.push_back('c');
		charVector.push_back('p');
		charVector.push_back('l');
		charVector.push_back('u');
		charVector.push_back('s');
		charVector.push_back('+');

		try
		{
			std::vector<char>::iterator ret;

			ret = easyfind(charVector, 'u');
			std::cout << "Find occurence: " << *ret << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "No occurence found" << std::endl;
		}
	}

	{
		std::vector<char> charVector;

		charVector.push_back('c');
		charVector.push_back('p');
		charVector.push_back('l');
		charVector.push_back('u');
		charVector.push_back('s');
		charVector.push_back('+');

		try
		{
			std::vector<char>::iterator ret;

			ret = easyfind(charVector, '-');
			std::cout << "Find occurence: " << *ret << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "No occurence found" << std::endl;
		}
	}

	return 0;
}
