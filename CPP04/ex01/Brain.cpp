#include "Brain.hpp"

////////////////////////////////////////////
////////        COPLIEN FORM        ////////

Brain::Brain( void )
{
    std::cout << "Default " << YELLOW << "Brain" << RESET
            << " constructor" << std::endl;
    return;
}

Brain::Brain(const Brain& other)
{
    *this = other;
    std::cout << YELLOW << "Brain" << RESET << "copied" << std::endl;
    return ;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = other._ideas[i];
    }
    return (*this);
} 

Brain::~Brain( void )
{
    std::cout << YELLOW << "Brain" << RESET << " has been destroyed by the destructor" << std::endl;
    return ;
}

////////////////////////////////////////////
////////      OTHER  FUNCTIONS      ////////
