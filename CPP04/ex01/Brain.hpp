# include <iostream>
#include "Animal.hpp"

#ifndef BRAIN_HPP
    #define BRAIN_HPP

class Brain
{
    private:
        std::string _ideas[100];
    public:
        // Canonical form
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();
        // Other
};
#endif