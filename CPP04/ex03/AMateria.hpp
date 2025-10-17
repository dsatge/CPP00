#ifndef AMATERIA_HPP
    #define AMATERIA_HPP
    
#include <iostream>
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

class AMateria
{
    protected:
        std::string _type;
    public:
        //////COPLIEN FORM
        AMateria(std::string const& type);
        AMateria(const AMateria &other);
        AMateria &operator=(const AMateria &other);
        virtual ~AMateria();
        ///////OTHER
        std::string const&  getType(void) const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target) ;
};
#endif
