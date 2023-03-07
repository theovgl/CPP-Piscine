#include "includes/RPN.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "RPN should one and only one argument" << std::endl;
		return 1;
	}

	try {
		RPN rpn(argv[1]);
		std::cout << rpn.evaluate(argv[1]) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
