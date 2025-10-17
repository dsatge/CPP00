#ifndef MATERIAICE_HPP
    #define MATERIAICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

class ICharacter;

class Ice : public AMateria
{
    protected:

    public:
        //////COPLIEN FORM
        Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        virtual ~Ice();
        ///////OTHER
        std::string const&  getType(void) const;
        AMateria* clone() const;
        void use(ICharacter& target);
};
#endif
