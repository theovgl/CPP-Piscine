#include <iostream>
#include <cstring>
#include <cstdlib>

bool	check_number(const std::string &input)
{
	int	i;
	int	pointCount;

	i = 0;
	pointCount = 0;
	if (input[i] == '-')
		i++;
	for (int j = i; input[j]; j++)
	{
		if (input[j] == '.' && pointCount > 0)
			return (false);
		if (input[j] == '.')
			pointCount++;
		if (input[j] == 'f' && j < static_cast<int>(input.length()))
			return(false);
		if ((input[j] < '0' || input[j] > '9') && input[j] != '.')
			return (false);
	}
	return (true);
}

void	convert_number(const std::string &input)
{
	if (check_number(input) == true)
	{
		double	res;
		res = static_cast<double>(atof(input.c_str()));
		if ((res >= 0 && res <= 32) || res == 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(res) << std::endl;
		std::cout << "int: " << static_cast<int>(res) << std::endl;
		std::cout << "float: " << static_cast<float>(res) << (static_cast<int>(res) == static_cast<float>(res) ? ".0f" : "") << std::endl;
		std::cout << "double: " << res << (static_cast<int>(res) == res ? ".0" : "") << std::endl;
	}
	else if (input.length() == 1 && isprint(input[0]))
	{
		char c = input[0];
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
	else if (input == "+inff"|| input == "+inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (input == "-inff"|| input == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		return (1);
	}
	convert_number(argv[1]);
	return (0);
}
