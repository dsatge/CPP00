#include <iostream>
#ifndef ANIMAL_HPP
    #define ANIMAL_HPP

class Animal
{
    protected:
        std::string _type;
    public:
        //////COPLIEN FORM
        Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        ~Animal();
        ///////OTHER
        void    makeSound(void);
};
#endif
