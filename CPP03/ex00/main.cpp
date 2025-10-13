#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap    ClapTrap("Rufus");
    ClapTrap.attack("Bob");
    ClapTrap.takeDamage(9);
    ClapTrap.beRepaired(9);
// ///////////// TEST EXHAUST FROM ATTACKS : Too many actions
//     ClapTrap.attack("Bob");
//     ClapTrap.attack("Bob");
//     ClapTrap.attack("Bob");
//     ClapTrap.attack("Bob");
//     ClapTrap.attack("Bob");
//     ClapTrap.attack("Bob");
//     ClapTrap.attack("Bob");
//     ClapTrap.attack("Bob");
//     ClapTrap.attack("Bob");
/////////////// TEST EXHAUST FROM HEALING : Too many actions
    ClapTrap.beRepaired(1);
    ClapTrap.beRepaired(1);
    ClapTrap.beRepaired(1);
    ClapTrap.beRepaired(1);
    ClapTrap.beRepaired(1);
    ClapTrap.beRepaired(1);
    ClapTrap.beRepaired(1);
    ClapTrap.beRepaired(1);
    ClapTrap.beRepaired(1);
///////////// TEST KILL : Too many damages
    ClapTrap.takeDamage(18);
    std::cout << RED << "----- ClapTrap Rufus is dead -----" << RESET << std::endl;
    ClapTrap.beRepaired(10);
    return 0;
}
