#include "Fixed.hpp"

// --------------------------------------------------------------------
// same as previous exercices

Fixed::Fixed (void) : _fixedvalue(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed (const int fixed)
{
    _fixedvalue = fixed << _bits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (const float fixed)
{
    _fixedvalue = roundf(fixed * (1 << _bits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed (const Fixed& src) : _fixedvalue(src._fixedvalue)
{
    std::cout << "Copy constructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Fixed& src)
{
    out << src.toFloat();
    return (out);
}

Fixed::~Fixed ( void )
{
    std::cout << "Destructor called" << std::endl;
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
        return (0);
    return (1);
}

bool    Fixed::operator>(const Fixed& other) const
{
    if (this->_fixedvalue < other._fixedvalue)
        return (0);
    return (1);
}

bool    Fixed::operator>=(const Fixed& other) const
{
    if (this->_fixedvalue >= other._fixedvalue)
        return (0);
    return (1);
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
        return (0);
    return (1);
}

bool    Fixed::operator!=(const Fixed& other) const
{
    if (this->_fixedvalue != other._fixedvalue)
        return (0);
    return (1);
}

// --------------------------------------------------------------------
//
// changing object operator

Fixed& Fixed::operator+(const Fixed& other)
{
    this->_fixedvalue += other._fixedvalue;
    return (*this);
}

Fixed& Fixed::operator-(const Fixed& other)
{
    this->_fixedvalue -= other._fixedvalue;
    return (*this);
}

Fixed& Fixed::operator*(const Fixed& other)
{
    this->_fixedvalue *= other._fixedvalue;
    return (*this);
}

Fixed& Fixed::operator/(const Fixed& other)
{
    this->_fixedvalue /= other._fixedvalue;
    return (*this);
}

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
// changing object operator extra

Fixed& Fixed::min(Fixed& left, Fixed& right)
{
    if (left < right)
        return (left);
    return (right);
}

const Fixed& min(const Fixed& left, const Fixed& right)
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

const Fixed& max(const Fixed& left, const Fixed& right)
{
    if (left > right)
        return (left);
    return (right);    
}
