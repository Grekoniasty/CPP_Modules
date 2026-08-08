#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : _integer(0) {}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->_integer = other.getRawBits();
    return (*this);
}

Fixed::~Fixed(void) {}

Fixed::Fixed(const int n)
{
    _integer = n << _fract;
}

Fixed::Fixed(const float f)
{
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



bool Fixed::operator>(const Fixed &other) const
{
    return this->_integer > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->_integer < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->_integer >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->_integer <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->_integer == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->_integer != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    if (other.getRawBits() == 0)
    {
           std::cerr << "Error: division by ";
        return 0;
    }
    else
        return Fixed(this->toFloat() / other.toFloat());
    std::cerr << "Division impossible" << std::endl;
    return 0;
}

Fixed &Fixed::operator++(void)
{
    ++this->_integer;
    return (*this);
}

Fixed &Fixed::operator--(void)
{
    --this->_integer;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++this->_integer;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --this->_integer;
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}
