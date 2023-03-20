#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::_print_database()
{
	std::map<std::string, float>::iterator it = _prices_history.begin();

	while (it != _prices_history.end()) {
		std::cout << it->first << "|" << it->second << std::endl;
		it++;
	}
}

void BitcoinExchange::_print_input_db()
{
	std::multimap<std::string, float>::iterator it = _amount.begin();

	while (it != _amount.end()) {
		std::cout << it->first << "|" << it->second << std::endl;
		it++;
	}
}

float BitcoinExchange::_compute_amount(float amount, const std::string& date_to_search)
{
	std::map<std::string, float>::const_iterator it = _prices_history.find(date_to_search);
	if (it != _prices_history.end())
		return it->second * amount;
	it = _prices_history.lower_bound(date_to_search);
	if (it == _prices_history.begin())
		return 0.00;
	it--;
	return it->second * amount;
}

void BitcoinExchange::print_result()
{
	std::multimap<std::string, float>::iterator it = _amount.begin();

	while (it != _amount.end()) {
		if (_check_date_format(it->first) == false) {
			std::cout << "\033[1;31m" << "Error: bad input => " << it->first << "\033[0m" << std::endl;
		} else if (it->first < "2009-01-03") {
			std::cout << "\033[1;31m" << "Bitcoin didn't exist yet on that date => " << it->first << "\033[0m" << std::endl;
		} else if (it->second < 0) {
			std::cout << "\033[1;31m" << "Error: not a positive number." << "\033[0m" << std::endl;
		} else if (it->second > 1000.00) {
			std::cout << "\033[1;31m" << "Error: too large number => " << it->second << "\033[0m" << std::endl;
		} else {
			std::cout << it->first << " => " << it->second << " = " << _compute_amount(it->second, it->first) << std::endl;
		}
		it++;
	}
}

bool BitcoinExchange::_check_date_format(const std::string& date)
{
	int	year;
	int	month;
	int	day;

	sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
	if (year < 1900) {
		return false;
	} else if (month < 1 || month > 12) {
		return false;
	} else if (day < 1 || day > 31) {
		return false;
	}
	return true;
}

int BitcoinExchange::openDatabase()
{
	_db_file.open("data.csv", std::ifstream::in);
	if (!_db_file.good()) {
		return 1;
	}

	std::string line;
	while (std::getline(_db_file, line)) {
		std::string	date, value;
		std::istringstream ss(line);

		std::getline(ss, date, ',');
		std::getline(ss, value);

		if (value.empty() || date == "date")
			continue ;
		else {
			_prices_history.insert(std::pair<std::string, float>(date, atof(value.c_str())));
		}
	}
	return 0;
}

int BitcoinExchange::openInput(const char *file_path)
{
	_input_file.open(file_path, std::ifstream::in);
	if (!_input_file.good()) {
		return 1;
	}

	std::string line;
	while (std::getline(_input_file, line)) {
		std::string	date, value;
		std::istringstream ss(line);

		std::getline(ss, date, '|');
		std::getline(ss, value);

		if (value.empty() || std::strstr(date.c_str(), "date") != NULL)
			continue ;
		else if (value.find_first_not_of("01234565789. ") != std::string::npos) {
			std::cout << "\033[1;31m" << "Error: not a valid input => " << value << "\033[0m" << std::endl;
			continue ;
		} else {
			_amount.insert(std::pair<std::string, float>(date, atof(value.c_str())));
		}
	}
	return 0;
}
