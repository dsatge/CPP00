#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

////////////////////////////////////////////
////////        COPLIEN FORM        ////////

WrongCat::WrongCat( void ) : WrongAnimal::WrongAnimal()
{
    this->_type = "WrongCat";
    std::cout << "Default " << PINK << "WrongCat" << RESET
            << " constructor" << std::endl;
    return;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal::WrongAnimal(other)
{
    return ;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        WrongAnimal::operator=(other);
    return (*this);
} 

WrongCat::~WrongCat( void )
{
    std::cout << PINK << "WrongCat" << RESET << " has been killed by the destructor" << std::endl;
    return ;
}

////////////////////////////////////////////
////////      OTHER  FUNCTIONS      ////////

void    WrongCat::makeSound(void) const
{
    std::cout << PINK << "Wrong miaouuu" << RESET << std::endl;
}