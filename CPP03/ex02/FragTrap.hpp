# include <iostream>
#include "ClapTrap.hpp"

#ifndef FRAGTRAP_HPP
    #define FRAGTRAP_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

class FragTrap : public ClapTrap
{
    private:

    public:
        // Canonical form
        FragTrap();
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();
        // Other
        FragTrap(const std::string name);
        void    highFivesGuy(void);
};
#endif