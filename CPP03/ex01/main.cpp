#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
    ScavTrap    ScavTrap("Rufus");
    ScavTrap.attack("Bob");
    ScavTrap.takeDamage(9);
    ScavTrap.beRepaired(9);
    ////// SPECIAL ABILITY FOR SCAVTRAP
    ScavTrap.guardGate();
    ClapTrap    ClapTrap("Bob");
    //////SPECIAL ABILITY IS NOT WORKING WITH CLAPTRAP
    // ClapTrap.guardGate();
    ScavTrap.takeDamage(100);
    std::cout << RED << "----- ScavTrap Rufus is dead -----" << RESET << std::endl;
    ScavTrap.beRepaired(10);
    return 0;
}
