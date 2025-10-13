#include "ClapTrap.hpp"

// --------------------------------------------------------------------
// Canonical form

ClapTrap::ClapTrap (void) : _hit_point(10), _energy_point(10), _attack_damage(0)
{
    std::cout << "ClapTrap has been created." << std::endl;
    return ;
}

ClapTrap::ClapTrap (const ClapTrap& other) : _name(other._name), _hit_point(10), _energy_point(10), _attack_damage(0)
{
    return ;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hit_point = other._hit_point;
        this->_energy_point = other._energy_point;
        this->_attack_damage = other._attack_damage;
    }
    return (*this);
}

ClapTrap::~ClapTrap (void)
{
    std::cout << "ClapTrap " << this->_name << " has been destroyed." << std::endl;
    return ;
}

// --------------------------------------------------------------------
// Other

ClapTrap::ClapTrap (const std::string name) : _name(name), _hit_point(10), _energy_point(10), _attack_damage(0)
{
    std::cout << "ClapTrap " << this->_name << " has been created." << std::endl;
    return ;
}

void    ClapTrap::attack(const std::string& target)
{
    std::cout << YELLOW << "//////////// ATTACK /////////////" << RESET << std::endl;
    if (this->_hit_point == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is " << RED << "dead" << RESET 
                << " and can not attack" << std::endl;
        return ;
    }

    if (this->_energy_point <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " can not attack "
                << target << ", there is " << RED << this->_energy_point
                << " EP" << RESET << " left." << std::endl;
        return ;
    }
    this->_energy_point--;
    std::cout << "ClapTrap " << this->_name << " attacks "
            << target << ", causing " << MAGENTA << this->_attack_damage
            << " damage" << RESET << "!" << std::endl;
    return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount < 0) // security: make sure it takes only positive dommage.
        amount *= -1;
    std::cout << YELLOW << "////////// TAKE DAMAGE //////////" << RESET << std::endl;
    if (this->_hit_point <= 0)
    {
        std::cout << "ClapTrap is already " << RED << "dead" << RESET << std::endl;
    }
    std::cout << "ClapTrap received " << MAGENTA << amount
            << " damages" << RESET << "." << std::endl;
    this->_hit_point -= amount;
    if (this->_hit_point < 0)
        this->_hit_point = 0;
    std::cout << "ClapTrap has " << GREEN << this->_hit_point << " HP" << RESET
            << " left." << std::endl;
}

void   ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << YELLOW << "//////////// HEALING ////////////" << RESET << std::endl;
    if (this->_hit_point <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " is " << RED << "dead" << RESET
                << " and can not heal" << std::endl;
        return ;    
    }
    if (this->_energy_point == 0)
    {
        std::cout << "ClapTrap " << this->_name << " can not heal. It has " << RED << "0 EP" << RESET << " left." << std::endl;
        return ;
    }
    this->_energy_point--;
    if (amount < 0) // security: make sure it takes only positive dommage.
        amount *= -1;
    this->_hit_point += amount;
    std::cout << "ClapTrap " << this->_name << " healed "
            << amount << "HP. It has now " << GREEN << this->_hit_point << " HP" << RESET
            << " and " << CYAN << this->_energy_point << " EP" << RESET << " left." << std::endl;
}

// --------------------------------------------------------------------
