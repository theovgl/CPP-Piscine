#include <iostream>
#include <string>
#include "Sed.hpp"

int	main(int argc, char *argv[])
{
	std::string newFileName;

	if (argc != 4) {
		std::cout << "Wrong number of argument" << std::endl;
		return (1);
	}
	newFileName = argv[1];
	newFileName.append(".replace");
	Sed sed(argv[2], argv[3]);
	if(sed.openFiles(argv[1], newFileName) == false)
	{
		std::cout << "An error occured while openning the file" << std::endl;
		return (1);
	}
	sed.replace();
	return (0);
}
