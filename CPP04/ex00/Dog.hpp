# include <iostream>
#include "Animal.hpp"

#ifndef DOG_HPP
    #define DOG_HPP

class Dog : public Animal
{
    private:

    public:
        // Canonical form
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();
        // Other
        void    makeSound(void) const;
};
#endif