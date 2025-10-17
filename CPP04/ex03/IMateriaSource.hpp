#ifndef IMATERIASOURCE_HPP
    #define IMATERIASOURCE_HPP

#include <iostream>
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

class IMateriaSource
{
    protected:

    public:
        //////COPLIEN FORM
        virtual ~IMateriaSource();
        ///////OTHER
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
