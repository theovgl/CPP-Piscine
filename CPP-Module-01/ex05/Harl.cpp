#include "Harl.hpp"
#include <iostream>
#include <string>

void Harl::complain(std::string level)
{
	typedef void (Harl::*ComplainFunction)(void);

	ComplainFunction complainPointer[4] = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};

	for (int i = 0; i < 4; i++) {
		if (complainList[i] == level) {
			(this->*complainPointer[i])();
		}
	}
}

void Harl::_debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl(void)
{
	complainList[0] = "DEBUG";
	complainList[1] = "INFO";
	complainList[2] = "WARNING";
	complainList[3] = "ERROR";
}

Harl::~Harl(void)
{
}
