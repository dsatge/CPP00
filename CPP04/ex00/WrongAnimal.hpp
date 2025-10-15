#include <iostream>
#ifndef WRONGANIMAL_HPP
    #define WRONGANIMAL_HPP

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

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        //////COPLIEN FORM
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);
        virtual ~WrongAnimal();
        ///////OTHER
        std::string   getType(void) const;
        virtual void    makeSound(void) const;
};
#endif
