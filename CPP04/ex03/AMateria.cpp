#include "Animal.hpp"

////////////////////////////////////////////
////////        COPLIEN FORM        ////////

Animal::Animal( void ) : _type("Animal")
{
    std::cout << "Default " << MAGENTA << this->_type << RESET
            << " constructor" << std::endl;
    return;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
    return ;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
} 

Animal::~Animal( void )
{
    std::cout << MAGENTA << "Animal" << RESET
            << " has been killed by the destructor" << std::endl;
    return ;
}

////////////////////////////////////////////
////////      OTHER  FUNCTIONS      ////////

std::string   Animal::getType(void) const
{
    return (this->_type);
}

// void    Animal::makeSound(void) const
// {
//     std::cout << MAGENTA << "*undistinct noise*" << RESET << std::endl;
// }