#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: not enough arguments" << std::endl;
	}
	
	BitcoinExchange btc;

	if (btc.openDatabase() != 0) {
		std::cerr << "Error: cannot open database" << std::endl;
		return 1;
	}
	if (btc.openInput(argv[1]) != 0) {
		std::cerr << "Error: cannot open input file" << std::endl;
		return 1;
	}

	btc.print_result();

	return (0);
}
