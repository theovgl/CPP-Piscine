#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <ostream>

const int Fixed::_bits = 8;

Fixed & Fixed::min(Fixed & nb1, Fixed & nb2)
{
	if (nb1.getRawBits() < nb2.getRawBits()) {
		return (nb1);
	}
	else
		return (nb2);
}

Fixed & Fixed::max(Fixed & nb1, Fixed & nb2)
{
	if (nb1.getRawBits() > nb2.getRawBits()) {
		return (nb1);
	}
	else
		return (nb2);
}

Fixed const & Fixed::min(Fixed const & nb1, Fixed const & nb2)
{
	if (nb1.getRawBits() < nb2.getRawBits()) {
		return (nb1);
	}
	else
		return (nb2);
}

Fixed const & Fixed::max(Fixed const & nb1, Fixed const & nb2)
{
	if (nb1.getRawBits() > nb2.getRawBits()) {
		return (nb1);
	}
	else
		return (nb2);
}

int Fixed::getRawBits(void) const
{
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
	this->_nb = 0;
}

Fixed::Fixed(const int nb)
{
	this->_nb = nb << this->_bits;
}

Fixed::Fixed(const float nb)
{
	this->_nb = roundf(nb * (1 << this->_bits));
}

Fixed::Fixed(Fixed const & src)
{
	this->_nb = src.getRawBits();
}

Fixed::~Fixed(void)
{
}

Fixed& Fixed::operator=(Fixed const & rhs)
{
	this->_nb = rhs.getRawBits();
	return (*this);
}

bool Fixed::operator>(Fixed const & rhs)
{
	if (this->_nb > rhs.getRawBits()) {
		return true;
	}
	return false;
}

bool Fixed::operator<(Fixed const & rhs)
{
	if (this->_nb < rhs.getRawBits()) {
		return true;
	}
	return false;
}

bool Fixed::operator>=(Fixed const & rhs)
{
	if (this->_nb >= rhs.getRawBits()) {
		return true;
	}
	return false;
}

bool Fixed::operator<=(Fixed const & rhs)
{
	if (this->_nb <= rhs.getRawBits()) {
		return true;
	}
	return false;
}

bool Fixed::operator==(Fixed const & rhs)
{
	if (this->_nb == rhs.getRawBits()) {
		return true;
	}
	return false;
}

bool Fixed::operator!=(Fixed const & rhs)
{
	if (this->_nb != rhs.getRawBits()) {
		return true;
	}
	return false;
}

Fixed Fixed::operator+(Fixed const & rhs)
{
	float result = this->toFloat() + rhs.toFloat();
	return Fixed(result);
}

Fixed Fixed::operator-(Fixed const & rhs)
{
	float result = this->toFloat() - rhs.toFloat();

	return Fixed(result);
}

Fixed Fixed::operator*(Fixed const & rhs)
{
	float	result = this->toFloat() * rhs.toFloat();

	return Fixed(result);
}

Fixed Fixed::operator/(Fixed const & rhs)
{
	float	result = this->toFloat() / rhs.toFloat();

	return Fixed(result);
}

Fixed& Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);

	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed save(this->toFloat());
	this->setRawBits(this->_nb + 1);

	return save;
}

Fixed& Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);

	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed save(this->getRawBits());

	this->setRawBits(this->getRawBits() - 1);

	return save;
}

std::ostream& operator<<(std::ostream & output, Fixed const & rhs)
{
	output << rhs.toFloat();
	return (output);
}
