#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "MateriaCure.hpp"
#include "MateriaIce.hpp"

////////////////////////////////////////////
////////        COPLIEN FORM        ////////

Character::Character( void ) : _name("Random Wizard")
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    std::cout << "Default Character constructor" << std::endl;
    return;
}

Character::Character(const Character& other)
{
    _name = other._name;
    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }    
    return ;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        _name = other._name;
        for (int i = 0; i < 4; i++)
        {
            delete _inventory[i];
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
        for (std::vector<AMateria*>::iterator it = _garbageMateria.begin(); it != _garbageMateria.end(); ++it)
            delete *it;
        _garbageMateria.clear();
    }
    return (*this);
} 

Character::~Character( void )
{
    for (std::vector<AMateria*>::iterator it = _garbageMateria.begin(); it != _garbageMateria.end(); ++it)
        delete *it;
    for (int i = 0; i < 4; i++)
        delete _inventory[i];
    std::cout << "Character " << _name << " has been killed by the destructor" << std::endl;
    return ;
}

////////////////////////////////////////////
////////      OTHER  FUNCTIONS      ////////

Character::Character(std::string name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    std::cout << "Character constructor" << std::endl;
    return;
}

std::string const & Character::getName() const
{
    return (_name);
}

void    Character::equip(AMateria* m)
{
    int empty_slot = 0;
    bool    inventory_full = true;
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] == NULL)
            inventory_full = false;
    }
    if (inventory_full == true)
    {
        _garbageMateria.push_back(m);
        return ;
    }
    while (_inventory[empty_slot] == NULL)
        empty_slot++;
    _inventory[empty_slot] = m;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3 || !_inventory[idx])
        return ;
    _garbageMateria.push_back(_inventory[idx]);
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3 || !_inventory[idx])
        return ;
    _inventory[idx]->use(target);
}
