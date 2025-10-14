#include "ScavTrap.hpp"

// --------------------------------------------------------------------
// Canonical form

ScavTrap::ScavTrap (void) : ClapTrap()
{
    this->_hit_point = 100;
    this->_energy_point = 50;
    this->_attack_damage = 20;
    std::cout << "ScavTrap default has been created." << std::endl;
    return ;
}

ScavTrap::ScavTrap (const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    return ;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return (*this);
}

ScavTrap::~ScavTrap (void)
{
    std::cout << "ScavTrap " << this->_name << " has been destroyed." << std::endl;
    return ;
}

// --------------------------------------------------------------------
// Other

ScavTrap::ScavTrap (const std::string name) : ClapTrap(name)
{
    this->_hit_point = 100;
    this->_energy_point = 50;
    this->_attack_damage = 20;
    std::cout << "ScavTrap " << this->_name << " has been created." << std::endl;
    return ;
}

void    ScavTrap::guardGate(void)
{
    std::cout << PINK << "ScavTrap " << this->_name << " is now in Gate keeper mode." << RESET << std::endl;
}
// --------------------------------------------------------------------
