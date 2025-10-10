# include <iostream>

#ifndef CLAPTRAP_HPP
    #define CLAPTRAP_HPP

class ClapTrap
{
    private:
        std::string _name;
        int         _hit_point;
    public:
        ClapTrap();
        ClapTrap(const int ClapTrap);
        ClapTrap(const float ClapTrap);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& src);
        ~ClapTrap();
        float   toFloat(void) const;
        int     toInt(void) const;

};
std::ostream& operator<<(std::ostream& out, const ClapTrap& src);
#endif