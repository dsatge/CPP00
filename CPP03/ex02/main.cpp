#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
    ///////SPECIAL ABILITY FOR FRAGTRAP
    FragTrap    FragTrap("Jean Baptiste Poquelin");
    FragTrap.takeDamage(50);
    FragTrap.attack("Bob");
    FragTrap.highFivesGuy();
    return 0;
}
