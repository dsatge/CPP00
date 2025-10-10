#include "Fixed.hpp"

// --------------------------------------------------------------------
// same as previous exercices

Fixed::Fixed (void) : _fixedvalue(0)
{
    return ;
}

Fixed::Fixed (const int fixed)
{
    _fixedvalue = fixed << _bits;
}

Fixed::Fixed (const float fixed)
{
    _fixedvalue = roundf(fixed * (1 << _bits));
}

Fixed::Fixed (const Fixed& src) : _fixedvalue(src._fixedvalue)
{
}

Fixed& Fixed::operator=(const Fixed& src)
{
    if (this != &src)
        this->_fixedvalue = src._fixedvalue;
    return (*this);
}

std::ostream& operator<<(std::ostream& out, const Fixed& src)
{
    out << src.toFloat();
    return (out);
}

Fixed::~Fixed ( void )
{
}

float   Fixed::toFloat(void) const
{
    return (static_cast<float>((this->_fixedvalue)) / (1 << _bits)); // utilise decalage binaire car 2^8 == 10 en code au lieu de 256
}

int   Fixed::toInt(void) const
{
    return (_fixedvalue >> _bits);
}

// --------------------------------------------------------------------
//
// comparasion operator

bool    Fixed::operator<(const Fixed& other) const
{
    if (this->_fixedvalue < other._fixedvalue)
        return (true);
    return (false);
}

bool    Fixed::operator>(const Fixed& other) const
{
    if (this->_fixedvalue > other._fixedvalue)
        return (true);
    return (false);
}

bool    Fixed::operator>=(const Fixed& other) const
{
    if (this->_fixedvalue >= other._fixedvalue)
        return (true);
    return (false);
}

bool    Fixed::operator<=(const Fixed& other) const
{
    if (this->_fixedvalue <= other._fixedvalue)
        return (0);
    return (1);
}

bool    Fixed::operator==(const Fixed& other) const
{
    if (this->_fixedvalue == other._fixedvalue)
        return (true);
    return (false);
}

bool    Fixed::operator!=(const Fixed& other) const
{
    if (this->_fixedvalue != other._fixedvalue)
        return (true);
    return (false);
}

// --------------------------------------------------------------------
//
// aritmetic operator

Fixed Fixed::operator+(const Fixed& other)
{
    Fixed   tmp(*this);
    tmp._fixedvalue += other._fixedvalue;
    return (tmp);
}

Fixed Fixed::operator-(const Fixed& other)
{
    Fixed   tmp = *this;
    tmp._fixedvalue -= other._fixedvalue;
    return (tmp);
}

Fixed Fixed::operator*(const Fixed& other)
{
    Fixed   result;
    long    tmp = static_cast<long>(this->_fixedvalue) * other._fixedvalue;
    result._fixedvalue = static_cast<int>(tmp >> _bits);
    return (result);
}

Fixed Fixed::operator/(const Fixed& other)
{
    if (other._fixedvalue == 0)
    {
        std::cerr << "Error: Div by 0 impossible" << std::endl;
        return (Fixed(0));
    }
    Fixed   result;
    long    tmp = (static_cast<long>(this->_fixedvalue) << _bits) / other._fixedvalue;
    result._fixedvalue = static_cast<int>(tmp);
    return (result);
}

// --------------------------------------------------------------------
//
// crementation operator

Fixed& Fixed::operator++(void) //pre-incrementation
{
    this->_fixedvalue++;
    return (*this);
}

Fixed Fixed::operator++(int) //post-incrementation
{
    Fixed   tmp(*this);
    this->_fixedvalue++;
    return (tmp);
}

Fixed& Fixed::operator--(void) //pre-decrementation
{
    this->_fixedvalue--;
    return (*this);
}

Fixed Fixed::operator--(int) //post-decrementation
{
    Fixed   tmp(*this);
    this->_fixedvalue--;
    return (tmp);
}

// --------------------------------------------------------------------
//
// min / max surcharge operator

Fixed& Fixed::min(Fixed& left, Fixed& right)
{
    if (left < right)
        return (left);
    return (right);
}

const Fixed& Fixed::min(const Fixed& left, const Fixed& right)
{
    if (left < right)
        return (left);
    return (right);
}


Fixed& Fixed::max(Fixed& left, Fixed& right)
{
    if (left > right)
        return (left);
    return (right);
}

const Fixed& Fixed::max(const Fixed& left, const Fixed& right)
{
    if (left > right)
        return (left);
    return (right);    
}
