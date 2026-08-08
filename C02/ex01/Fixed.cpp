#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : _integer(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_integer = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_integer = n << _fract;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	_integer = roundf(f * (1 << _fract));
}

float Fixed::toFloat(void) const
{
	return (float)_integer / (1 << _fract);
}

int Fixed::toInt(void) const
{
	return _integer >> _fract;
}

int Fixed::getRawBits(void) const
{
	return (this->_integer);
}

void Fixed::setRawBits(int const raw)
{
	this->_integer = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	(void)fixed;
	return (out);
}