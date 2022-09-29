#include <iostream>

int	main(int ac, char **av)
{
	int		j;

	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	j = 1;
	while (av[j])
	{
		std::string str(av[j]);
		for (size_t i = 0; i < str.length(); i++)
			std::cout << (char)toupper(str.at(i));
		j++;
	}
	std::cout << std::endl;
	return (0);
}
