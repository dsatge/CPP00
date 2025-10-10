#include "Fixed.hpp"

// --------------------------------------------------------------------
// Canonical form

Fixed::Fixed (void) : _fixedvalue(0)
{
    return ;
}

Fixed::Fixed ()
{
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
