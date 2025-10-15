# include <iostream>
#include "Animal.hpp"

#ifndef CAT_HPP
    #define CAT_HPP

class Cat : public Animal
{
    private:

    public:
        // Canonical form
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat();
        // Other
        void    makeSound(void) const;
};
#endif