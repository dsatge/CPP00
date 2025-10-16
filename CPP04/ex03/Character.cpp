#include "Character.hpp"
#include "ICharacter.hpp"

////////////////////////////////////////////
////////        COPLIEN FORM        ////////

Character::Character( void ) : _index_inv(0)
{
    std::cout << "Default Character constructor" << std::endl;
    return;
}

Character::Character(const Character& other)
{
    this->_name = other._name;
    this->_index_inv = other._index_inv;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = other._inventory[i];
    return ;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_index_inv = other._index_inv;
        for (int i = 0; i < 4; i++)
            this->_inventory[i] = other._inventory[i];
    }
    return (*this);
} 

Character::~Character( void )
{
    std::cout << "Character has been killed by the destructor" << std::endl;
    return ;
}

////////////////////////////////////////////
////////      OTHER  FUNCTIONS      ////////

Character::Character(std::string name) : _name(name)
{
    std::cout << this->_name << " Character constructor" << std::endl;
    return;
}

void    equip(AMateria* m)
{
    thi
}

