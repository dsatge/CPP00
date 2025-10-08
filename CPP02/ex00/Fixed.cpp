#include "Fixed.hpp"

Fixed::Fixed ( void ) : _fixedvalue(0)
{
    std::cout << "Default constructor called" << std::endl;
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

Fixed::~Fixed ( void )
{
    std::cout << "Destructor called" << std::endl;
}

int   Fixed::getRawBits( void )const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedvalue);
}

void    Fixed::setRawBits( int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedvalue = raw;
}
