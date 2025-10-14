# include <iostream>

#ifndef CLAPTRAP_HPP
    #define CLAPTRAP_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define PINK    "\033[38;5;205m"
#define BOLD    "\033[1m"

class ClapTrap
{
    protected:
        std::string _name;
        int         _hit_point;
        int         _energy_point;
        int         _attack_damage;

    public:
        // Canonical form
        ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();
        // Other
        ClapTrap(const std::string name);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
#endif