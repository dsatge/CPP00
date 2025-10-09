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
        Fixed(const Fixed& other);
        ~Fixed();
        float   toFloat(void) const;
        int     toInt(void) const;

        // comparasion operator
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        // changing object operator
        Fixed& operator+(const Fixed& other);
        Fixed& operator-(const Fixed& other);
        Fixed& operator*(const Fixed& other);
        Fixed& operator/(const Fixed& other);
        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);

        // changing object operator extra
        Fixed& min(Fixed& left, Fixed& right);
        const Fixed& min(const Fixed& left, const Fixed& right);
        Fixed& max(Fixed& left, Fixed& right);
        const Fixed& max(const Fixed& left, const Fixed& right);
        
};
std::ostream& operator<<(std::ostream& out, const Fixed& src);
#endif