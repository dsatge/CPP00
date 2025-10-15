#include "Cat.hpp"
#include "Animal.hpp"

////////////////////////////////////////////
////////        COPLIEN FORM        ////////

Cat::Cat( void ) : Animal::Animal()
{
    this->_type = "Cat";
    std::cout << "Default " << CYAN << "Cat" << RESET
            << " constructor" << std::endl;
    return;
}

Cat::Cat(const Cat& other) : Animal::Animal(other)
{
    return ;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        Animal::operator=(other);
    return (*this);
} 

Cat::~Cat( void )
{
    std::cout << CYAN << "Cat" << RESET << " has been killed by the destructor" << std::endl;
    return ;
}

////////////////////////////////////////////
////////      OTHER  FUNCTIONS      ////////

void    Cat::makeSound(void) const
{
    std::cout << CYAN << "miaouuu" << RESET << std::endl;
}