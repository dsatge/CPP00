# include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

#ifndef DOG_HPP
    #define DOG_HPP

class Dog : public Animal
{
    private:
        Brain* _brain;
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