#pragma once
#include <iostream> 

//Orthodox Canonical Form. Constructor, Copy Constructor, copy assigment constructor, destructor.
class Fixed
{
    int _integer;
    static const int _fract = 8;

    public:
        Fixed(); 
        Fixed(const Fixed &other);
        Fixed &operator =(const Fixed &other);
        ~Fixed(); 
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};