# include "includes/PmergeMe.hpp"

int main(int argc, const char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error: not enough arguments" << std::endl;
		return 1;
	}

	PmergeMe< std::vector<int> >	vector;
	PmergeMe< std::list<int> >		list;

	try {
		vector.fill_container( argv );
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	try {
		list.fill_container( argv );
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	vector.print(false);

	try {
		vector.compute();
		list.compute();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	list.print(true);
	vector.print_time();
	list.print_time();

	return (0);
}
