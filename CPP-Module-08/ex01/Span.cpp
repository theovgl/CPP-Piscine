#include "Span.hpp"

Span::Span(void):
	_max(5)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int max):
	_max(max)
{
	std::cout << "Span constructor called" << std::endl;
}

void Span::addNumber(int toAdd)
{
	if (this->_array.size() >= this->_max)
		throw std::exception();
	else
		this->_array.push_back(toAdd);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (end - begin + this->_array.size() > this->_max)
		throw std::exception();
	this->_array.resize(end - begin + _array.size());
	std::copy(begin, end, this->_array.begin());
}

int Span::shortestSpan(void)
{
	int					shortestSpan;
	std::vector<int>	cpy;
	std::vector<int>	difference(this->_max);

	if (this->_array.size() <= 1)
		throw std::exception();
	cpy = this->_array;
	std::sort(cpy.begin(), cpy.end());
	std::adjacent_difference(cpy.begin(), cpy.end(), difference.begin());
	shortestSpan = *std::min_element(difference.begin() + 1, difference.end());

	return (shortestSpan);
}

int Span::longestSpan(void)
{
	int					longestSpan;
	std::vector<int>	cpy;

	if (this->_array.size() <= 1)
		throw std::exception();
	cpy = this->_array;
	std::sort(cpy.begin(), cpy.end());
	longestSpan = cpy.back() - cpy.front();

	return (longestSpan);
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}
