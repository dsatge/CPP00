#include "Dog.hpp"
#include "Animal.hpp"

////////////////////////////////////////////
////////        COPLIEN FORM        ////////

Dog::Dog( void ) : Animal::Animal()
{
    this->_type = "Dog";
    std::cout << "Default " << GREEN << "Dog" << RESET
            << " constructor" << std::endl;
    return;
}

Dog::Dog(const Dog& other) : Animal::Animal(other)
{
    return ;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        Animal::operator=(other);
    return (*this);
} 

Dog::~Dog( void )
{
    std::cout << GREEN << "dog" << RESET << " has been killed by the destructor" << std::endl;
    return ;
}

////////////////////////////////////////////
////////      OTHER  FUNCTIONS      ////////

void    Dog::makeSound(void) const
{
    std::cout << GREEN << "wouf wooouf" << RESET << std::endl;
}