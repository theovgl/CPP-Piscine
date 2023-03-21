#ifndef BITCOINEXCHANG_HPP
# define BITCOINEXCHANG_HPP

# include <fstream>
# include <iostream>
# include <map>
# include <cstdlib>
# include <sstream>
# include <iomanip>
# include <ctime>
# include <cstring>

class BitcoinExchange
{

public:

	BitcoinExchange();
	~BitcoinExchange();

	int		openDatabase();
	int		openInput(const char* file_path);
	void	print_result();
private:
	std::ifstream _db_file;
	std::ifstream _input_file;

	std::map<std::string, float>		_prices_history;
	std::multimap<std::string, float>	_amount;

	void	_print_database();
	void	_print_input_db();

	bool	_check_date_format(const std::string& date);
	float	_compute_amount(float amount, const std::string& date_to_find);
};

#endif
