#include "Animal.hpp"

////////////////////////////////////////////
////////        COPLIEN FORM        ////////

Animal::Animal( void ) : _type("Animal")
{
    std::cout << "Default Animal constructor" << std::endl;
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
    std::cout << "Animal has been killed by the destructor" << std::endl;
    return ;
}

////////////////////////////////////////////
////////      OTHER  FUNCTIONS      ////////

void    Animal::makeSound(void)
{
    std::cout << "couic-uhuhuh-meow-wouf-tweet-sfjsj\n"
            << "*Undistinct noises*" << std::endl;
}