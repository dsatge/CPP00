#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"

#ifndef ICHARACTER_HPP
    #define ICHARACTER_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

class ICharacter
{
    protected:
        AMateria*   _inventory[4];
        std::string _name;
    public:
        //////COPLIEN FORM
        ICharacter();
        ICharacter(const ICharacter& other);
        ICharacter& operator=(const ICharacter& other);
        virtual ~ICharacter();
        ///////OTHER
        ICharacter(std::string name);
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;};
#endif
