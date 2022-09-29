#include "iter.hpp"
#include <iostream>
#include <string>

void	print_int(const int& value)
{
	std::cout << value << std::endl;
}

void	print_str(const std::string &value)
{
	std::cout << value << std::endl;
}

void 	print_float(const float& value)
{
	std::cout << value << std::endl;
}

int main(void)
{
	std::cout << "==== Test INT ====" << std::endl;
	int array1[] = {1, 3, 43, -6, 127};

	iter(&array1[0], 5, print_int);

	std::cout << "==== Test STRING ====" << std::endl;
	std::string array2[] = {"hello", "bonjour", "gutten tag"};
	iter(&array2[0], 3, print_str);

	std::cout << "==== Test FLOAT ====" << std::endl;
	float array3[] = {1.89540, 86.2345, 5.0, -6.788, 127.127};
	iter(&array3[0], 5, print_float);
	
	return 0;
}
