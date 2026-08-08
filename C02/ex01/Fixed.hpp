#pragma once
#include <iostream>

// Orthodox Canonical Form + int/float constructors + conversion methods
class Fixed
{
    int                 _integer;
    static const int    _fract = 8;

    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();

        Fixed(const int n);
        Fixed(const float f);

        float   toFloat(void) const;
        int     toInt(void) const;

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

// overload operator<< so that printing a Fixed prints its float value
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);