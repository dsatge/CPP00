#include "ICharacter.hpp"

////////////////////////////////////////////
////////        COPLIEN FORM        ////////

ICharacter::ICharacter( void )
{
    std::cout << "Default ICharacter constructor" << std::endl;
    return;
}

ICharacter::ICharacter(const ICharacter& other)
{
    this->_name = other._name;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = other._inventory[i];
    return ;
}

ICharacter& ICharacter::operator=(const ICharacter& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        for (int i = 0; i < 4; i++)
            this->_inventory[i] = other._inventory[i];
    }
    return (*this);
} 

ICharacter::~ICharacter( void )
{
    std::cout << "ICharacter has been killed by the destructor" << std::endl;
    return ;
}

////////////////////////////////////////////
////////      OTHER  FUNCTIONS      ////////

ICharacter::ICharacter(std::string name) : _name(name)
{
    std::cout << this->_name << " ICharacter constructor" << std::endl;
    return;
}

