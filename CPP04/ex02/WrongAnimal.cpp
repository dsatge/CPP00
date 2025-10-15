#include "WrongAnimal.hpp"

////////////////////////////////////////////
////////        COPLIEN FORM        ////////

WrongAnimal::WrongAnimal( void ) : _type("WrongAnimal")
{
    std::cout << "Default " << RED << this->_type << RESET
            << " constructor" << std::endl;
    return;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
    return ;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
} 

WrongAnimal::~WrongAnimal( void )
{
    std::cout << RED << "WrongAnimal" << RESET
            << " has been killed by the destructor" << std::endl;
    return ;
}

////////////////////////////////////////////
////////      OTHER  FUNCTIONS      ////////

std::string   WrongAnimal::getType(void) const
{
    return (this->_type);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << RED << "*very wrong undistinct noise*" << RESET << std::endl;
}