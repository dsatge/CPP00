# include <iostream>
#include "WrongAnimal.hpp"

#ifndef WRONGCAT_HPP
    #define WRONGCAT_HPP

class WrongCat : public WrongAnimal
{
    private:

    public:
        // Canonical form
        WrongCat();
        WrongCat(const WrongCat& other);
        WrongCat& operator=(const WrongCat& other);
        ~WrongCat();
        // Other
        void    makeSound(void) const;
};
#endif