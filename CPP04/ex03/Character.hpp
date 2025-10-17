#ifndef CHARACTER_HPP
    #define CHARACTER_HPP

#include <iostream>
#include <vector>
#include "ICharacter.hpp"
#include "AMateria.hpp"


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

class AMateria;

class Character : public ICharacter
{
    protected:
        AMateria*   _inventory[4];
        std::string _name;
        std::vector <AMateria*> _garbageMateria;
    public:
        //////COPLIEN FORM
        Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        virtual ~Character();
        ///////OTHER
        Character(std::string name);
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};
#endif
