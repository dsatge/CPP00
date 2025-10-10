#include "Fixed.hpp"

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

Fixed& Fixed::operator=(const Fixed& src)
{
    if (this != &src)
        this->_fixedvalue = src._fixedvalue;
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
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
