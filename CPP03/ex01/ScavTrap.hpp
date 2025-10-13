# include <iostream>
#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
    #define SCAVTRAP_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

class ScavTrap : public ClapTrap
{
    private:

    public:
        // Canonical form
        ScavTrap();
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();
        // Other
};
#endif