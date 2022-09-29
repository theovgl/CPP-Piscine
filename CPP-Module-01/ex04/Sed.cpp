#include "Sed.hpp"
#include <fstream>
#include <iostream>
#include <string>

bool Sed::openFiles(char *filename, const std::string newFile)
{
	this->_input.open(filename);
	if (!_input)
		return (false);
	this->_output.open(newFile.c_str());
	if (!_output)
		return (false);
	return (true);
}

std::string Sed::_copyInput()
{
	std::string ret;

	char c = this->_input.get();
	while (this->_input.good()) {
		ret.push_back(c);
		c = this->_input.get();
	}
	return (ret);
}

void Sed::replace()
{
	std::string	newString;

	newString = this->_copyInput();
	for (size_t i = 0; i < newString.length(); i++) {
		if (newString.compare(i, this->_s1.length(), this->_s1) == 0) {
			newString.erase(i, this->_s1.length());
			newString.insert(i, this->_s2);
		}
	}
	this->_output << newString;
}

Sed::Sed(std::string s1, std::string s2)
{
	this->_s1 = s1;
	this->_s2 = s2;
}

Sed::~Sed(void)
{
	this->_input.close();
	this->_output.close();
}
