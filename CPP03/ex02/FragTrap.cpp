#include "FragTrap.hpp"

// --------------------------------------------------------------------
// Canonical form

FragTrap::FragTrap (void) : ClapTrap()
{
    this->_hit_point = 100;
    this->_energy_point = 50;
    this->_attack_damage = 20;
    std::cout << "FragTrap default has been created." << std::endl;
    return ;
}

FragTrap::FragTrap (const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    return ;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return (*this);
}

FragTrap::~FragTrap (void)
{
    std::cout << "FragTrap " << this->_name << " has been destroyed." << std::endl;
    return ;
}

// --------------------------------------------------------------------
// Other

FragTrap::FragTrap (const std::string name) : ClapTrap(name)
{
    this->_hit_point = 100;
    this->_energy_point = 100;
    this->_attack_damage = 30;
    std::cout << "FragTrap " << this->_name << " has been created." << std::endl;
    return ;
}

void    FragTrap::highFivesGuy(void)
{
    std::cout << PINK << "FragTrap " << this->_name << " says: Hey! Give me five !" << RESET << std::endl;
}
// --------------------------------------------------------------------
