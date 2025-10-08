# include <iostream>
# include <cmath>

#ifndef FIXED_HPP
    #define FIXED_HPP

class Fixed
{
    private:
        int _fixedvalue;
        static const int _bits = 8;

    public:
        Fixed();
        Fixed(const int fixed);
        Fixed(const float fixed);
        Fixed(const Fixed& src);
        ~Fixed();
        float   toFloat(void) const;
        int     toInt(void) const;

};
std::ostream& operator<<(std::ostream& out, const Fixed& src);
#endif