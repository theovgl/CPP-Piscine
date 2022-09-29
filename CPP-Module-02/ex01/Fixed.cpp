#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <math.h>
#include <ostream>

const int Fixed::_bits = 8;

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_nb);
}

void Fixed::setRawBits(int const raw)
{
	this->_nb = raw;
}

int Fixed::toInt(void) const
{
	return (this->_nb >> this->_bits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_nb / (1 << this->_bits));
}

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_nb = 0;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->_nb = nb << this->_bits;
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->_nb = roundf(nb * (1 << this->_bits));
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_nb = src.getRawBits();
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_nb = rhs.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream & output, Fixed const & rhs)
{
	output << rhs.toFloat();
	return (output);
}
